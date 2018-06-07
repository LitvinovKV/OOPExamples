#include "Counter.h"

class MyString {
	Counter* m_pMyCounter; //��������� �� "����" Counter 
public:
	
	MyString(); //����������� �� ���������
	MyString(char*); //����������� � ����������
	~MyString();
	
	//��������������� �����: 
	MyString(MyString&);//����������� �����������
	MyString(MyString&&); //������������ move-����������� &&
	MyString& operator= (MyString&); //�������� ������������ operator=
	MyString& operator= (MyString&&); //����������� operator=&&

	static void PrintAll();
	static void Sorting();
	static void EditRegister();
};
