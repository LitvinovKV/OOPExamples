#include <string>
#include "myString.h"
using namespace std;

// ќпределение конструктора.
MyString::MyString(char* str)
{
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
}

MyString& MyString::operator= (const MyString& other)
{
	if (other.m_pStr != nullptr) {
		if (this != &other)
		{
			if (other.m_pStr == nullptr) return MyString();
			delete[] m_pStr;
			m_pStr = new char[strlen(other.m_pStr) + 1];
			strcpy(m_pStr, other.m_pStr);
		}
	}
	return *this;
}

// ќпределение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
	m_pStr = nullptr;
}

MyString::MyString()
{
	m_pStr = new char[1];
	m_pStr = 0;
}

// конструктор копировани€ дл€ строки
MyString::MyString(const MyString& other)
{
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
}

char* MyString::operator*() {
	return m_pStr;
}

//char MyString::operator[](int index)
//{
//	//if (index >= strlen(m_pStr))
//	//	throw out_of_range;
//	return m_pStr[index];
//}