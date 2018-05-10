#include "Pair.h"

class Base {
    Pair* m_pBase;
    size_t m_count;
    size_t m_capacity;
    public:
        Base();
        Base(const Base& other_bd);
        Base(const Base&& other_bd);
        ~Base();
        void getBase(size_t&, size_t&, Pair*&) const;
        void deletePair(const char* key);

        Base& operator=(const Base& other_bd);
        Base& operator=(Base&& other_bd);
        MyData& operator[](const char* key);
        friend ostream& operator<< (ostream& out, const Base& bd);
};