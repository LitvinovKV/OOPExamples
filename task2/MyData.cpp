#include "MyData.h"

MyData::MyData() {
    m_sex = UNDEF;
    m_age = 0;
    m_job = nullptr;
    m_salary = 0.f;
}

MyData::MyData(Sex& sex, size_t& age, const char* job, float& salary) {
    m_sex = sex;
    m_salary = salary;
    m_age = age;
    m_job = new char(strlen(job) + 1);
    strcpy(m_job, job);
}

MyData::MyData(Sex&& sex, size_t&& age, const char* job, float&& salary) {
    m_sex = sex;
    m_salary = salary;
    m_age = age;
    m_job = new char(strlen(job) + 1);
    strcpy(m_job, job);
}

MyData::MyData(const MyData& other_date) {
    m_age = other_date.m_age;
    m_sex = other_date.m_sex;
    m_salary = other_date.m_salary;
    m_job = new char[strlen(other_date.getJobTitle()) + 1];
    strcpy(m_job, other_date.getJobTitle());
}

MyData::MyData(MyData&& other_date) {
    m_age = other_date.m_age;
    m_sex = other_date.m_sex;
    m_salary = other_date.m_salary;
    m_job = new char[strlen(other_date.getJobTitle()) + 1];
    strcpy(m_job, other_date.getJobTitle());
}

MyData::~MyData() {
    delete[] m_job;
    m_job = nullptr;
}

const char* MyData::getJobTitle() const {
    return m_job;
}


const void MyData::getData(Sex& sex, size_t& age, char*& job, float& salary) const{
    sex = m_sex;
    age = m_age;
    salary = m_salary;
    job = m_job;
}

MyData& MyData::operator=(const MyData& other_date) {
    if (this != &other_date) {
        m_age = other_date.m_age;
        m_salary = other_date.m_salary;
        m_sex = other_date.m_sex;
        delete[] m_job;
        m_job = new char[strlen(other_date.getJobTitle()) + 1];
        strcpy(m_job, other_date.getJobTitle());
    }
    return *this;
}

MyData& MyData::operator=(MyData&& other_date) {
    if (this != &other_date) {
        m_age = other_date.m_age;
        m_salary = other_date.m_salary;
        m_sex = other_date.m_sex;
        delete[] m_job;
        m_job = new char[strlen(other_date.getJobTitle()) + 1];
        strcpy(m_job, other_date.getJobTitle());
    }
    return *this;
}