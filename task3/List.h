#include "Node.h"
#include <fstream>

class List {
	Node m_Head;	// ��������� �������, ������� �������� ��������� ������ ������
	Node m_Tail;	// ��������� �������, ������� �������� ��������� ����� ������
	unsigned int m_size;	//���������� ���������
public:
	List(); //������������ Head, Tail � m_size 

	//����������� -------------
	List& operator=(const List&); //�������� ������������
	List(const List&); //����������� �����������
	List(List&&); //move-�����������
	List& operator=(List&&); //�����������

	//------------------------

	void AddToHead(Circle&); //�����, ������� ��������� ������� � ������ ������
	void AddToTail(Circle&); //�����, ������� ��������� ������� � ����� ������
	bool DeleteOneElement(Circle&); //�������� �� ������ 1��� ��������, c ����������� ����������
	int DeleteElements(Circle&); //�������� �� ������ ���� ���������, c ���� ����������
	friend ostream& operator<<(ostream&, const List&);
	void Sort();
	void DeleteAll();
	void SaveInFile();
	void ReadFromFile();
};

