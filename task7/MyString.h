#include <iostream>
using namespace std;
class MyString
{
	char* m_pStr;
public:
	MyString();
	MyString(char*);
	~MyString();
	MyString& operator= (const MyString&);
	MyString(const MyString& other); // ����������� ����������� ��� ������
	
	char* operator*();
	friend ostream& operator<< (ostream&, const MyString&);
};