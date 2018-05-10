#include "MyData.h"

class Pair {
    char* m_key;
    MyData m_data;

    public:
        Pair();
        Pair(const char*, const MyData&);

        char* getKey() const;
        void getPairData(MyData::Sex&, size_t&, char*&, float&) const;

        Pair& operator=(const Pair&);
        Pair& operator=(const char* key);
        bool operator==(const char*) const;
        friend ostream& operator<< (ostream&, const Pair&);

        ~Pair();
        friend class Base;
};