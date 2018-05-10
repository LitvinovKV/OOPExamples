#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class MyData {
    public:
        enum Sex {UNDEF, MALE, FMALE};
    private:
        Sex m_sex;
        size_t m_age;
        char* m_job;
        float m_salary;
    public:
        MyData();
        MyData(Sex&, size_t&, const char*, float&);
        MyData(Sex&&, size_t&&, const char*, float&&);
        MyData(const MyData&);
        MyData(MyData&&);
        
        const char* getJobTitle() const;
        const void getData(Sex&, size_t&, char*&, float&) const;

        MyData& operator=(const MyData&);
        MyData& operator=(MyData&&);
        
        ~MyData();
};