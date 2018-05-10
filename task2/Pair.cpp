#include "Pair.h"

Pair::Pair() {
    m_key = nullptr;
}

Pair::Pair(const char* key, const MyData& data) {
    m_key = new char[strlen(key) + 1];
    strcpy(m_key, key);
    m_data = data;
}

Pair::~Pair() {
    m_data.~MyData();
    delete[] m_key;
    m_key = nullptr;
}

bool Pair::operator==(const char* key) const {
    if (strcmp(key, m_key) == 0) return true;
    else return false;
}


char* Pair::getKey() const {
    return m_key;
}

void Pair::getPairData(MyData::Sex& sex, size_t& age, char*& job, float& salary) const {
    m_data.getData(sex, age, job, salary);
}

ostream& operator<< (ostream& out, const Pair& pair) {
    size_t age;
    char* job;
    float salary;
    MyData::Sex sex;
    pair.getPairData(sex, age, job, salary);
    cout << "KEY(NAME): \"" << pair.getKey() << "\"\n";
    cout << "DATA: sex = " << sex << " age = " << age << 
            " Job Title = " << job << " salary = " << salary;
    return out;
}

Pair& Pair::operator=(const Pair& other_pair) {
    m_key = new char[strlen(other_pair.getKey()) + 1];
    strcpy(m_key, other_pair.getKey());
    size_t age;
    float salary;
    char* job;
    MyData::Sex sex;
    other_pair.getPairData(sex, age, job, salary);
    m_data = MyData(sex, age, job, salary);
    return *this;
}

Pair& Pair::operator=(const char* key) {
    m_key = new char[strlen(key) + 1];
    strcpy(m_key, key);
    return *this;
}