//�������� "��������" ��� ������ � �������� ��������������� ������, 
//������� � ��������� �������� �������� ������������ ������
#include <iostream>
#include <cstring>

using namespace std;

class Counter
{
	char* m_pStr; //��������� �� ����������� ����������� ������ 
	unsigned int m_nOwners; //������� ������������� ������ ������
	Counter* m_pNext; //��������� �� ��������� Counter
	
	//����������� ����������-------------------
	static Counter* m_Head;
	static unsigned int m_curCounters; //������� ����������

	//������-------------------------
	Counter(); //����������� �� ���������
	Counter(char*); //����������� � ����������
	~Counter();
	void AddNewOwners(); //�������� ������������
	void DeleteOwner(); //������ ������������ 
	
	friend class MyString;
};
