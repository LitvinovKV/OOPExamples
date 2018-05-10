#include "Base.h"

Base::Base() {
    m_count = 0;
    m_capacity = 3;
    m_pBase = new Pair[m_capacity];
}

Base::Base(const Base& other_bd) {
    size_t count, capacity;
    Pair* pBase;
    other_bd.getBase(count, capacity, pBase);
    m_count = count;
    m_capacity = capacity;
    m_pBase = new Pair[capacity];
    for (size_t i = 0; i < count; i++)
        m_pBase[i] = pBase[i];
}

Base::Base(const Base&& other_bd) {
    size_t count, capacity;
    Pair* pBase;
    other_bd.getBase(count, capacity, pBase);
    m_count = count;
    m_capacity = capacity;
    m_pBase = new Pair[capacity];
    for (size_t i = 0; i < count; i++)
        m_pBase[i] = pBase[i];
}

void Base::getBase(size_t& count, size_t& capacity, Pair*& pBase) const {
    count = m_count;
    capacity = m_capacity;
    pBase = m_pBase;
}

Base::~Base() {
    for (size_t i = 0; i < m_capacity; i++)
        m_pBase[i].~Pair();
    m_pBase = nullptr;
}

void Base::deletePair(const char* key) {
    int index_del = -1;
    for(size_t i = 0; i < m_count; i++) {
        if (m_pBase[i] == key) {
            index_del = i;
            break;
        }
    }
    //если такого ключа нет
    if (index_del == -1 ) return;
    
    //удалить совпавший с ключем элемент 
    m_pBase[index_del].~Pair();
    //сместить ключи на один влево
    for (size_t i = index_del; i < m_count - 1; i++)
        m_pBase[i] = m_pBase[i + 1];
    //очистить последний элемент
    m_pBase[m_count - 1].~Pair();
    m_count--;
}

ostream& operator<< (ostream& out, const Base& bd) {
    out << "ALL DATAS: \n";
    for (size_t i = 0; i < bd.m_count; i++) {
        cout << bd.m_pBase[i] << "\n";
    }
    return out;
}

MyData& Base::operator[](const char* key) {
    for(size_t i = 0; i < m_count; i++) {
        if (m_pBase[i] == key)
            //вернуть найденный объект MyData 
            return m_pBase[i].m_data;
    }

    //если сотрудник не найден
    if (m_count >= m_capacity) {
        m_capacity += 3;
        Pair* pBase = new Pair[m_capacity];

        //перезаписать данные в увеличенный массив
        for (size_t i = 0; i < m_count; i++) {
            pBase[i] = m_pBase[i];
            m_pBase[i].~Pair();
        }
        //перенаправить указатель
        m_pBase = pBase;
    }
    //увеличить счетчик кол-ва данных
    m_pBase[m_count] = key;
    m_count++;
    //вернуть пустой объект MyData, чтобы туда были занесены данные
    return m_pBase[m_count - 1].m_data;
}

Base& Base::operator=(const Base& other_bd) {
    size_t count, capacity;
    Pair* pBase;
    other_bd.getBase(count, capacity, pBase);
    m_count = count;
    m_capacity = capacity;
    m_pBase = new Pair[m_capacity];
    for (size_t i = 0; i < m_count; i++)
        m_pBase[i] = other_bd.m_pBase[i];
    return *this;
}

Base& Base::operator=(Base&& other_bd) {
    size_t count, capacity;
    Pair* pBase;
    other_bd.getBase(count, capacity, pBase);
    m_count = count;
    m_capacity = capacity;
    m_pBase = new Pair[m_capacity];
    for (size_t i = 0; i < m_count; i++)
        m_pBase[i] = other_bd.m_pBase[i];
    return *this;
}