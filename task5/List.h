#include "Node.h"
class List {
	Node m_Head;	// ��������� �������, ������� �������� ��������� ������ ������
	Node m_Tail;	// ��������� �������, ������� �������� ��������� ����� ������
	unsigned int m_size;	//���������� ���������
public:
	List(); //������������ Head, Tail � m_size 

	//����� -------------
	List& operator=(const List&); //�������� ������������
	List(const List&); //����������� �����������
	List(List&&); //move-�����������
	List& operator=(List&&); //�����������
	//------------------------

	void AddToHead(Shape&); //�����, ������� ��������� ������� � ������ ������
	void AddToTail(Shape&); //��������� ������� � ����� ������
	
	bool DeleteOneElement(Shape&); //�������� �� ������ 1��� ��������, c ����������� ����������
	int DeleteElements(Shape&); //�������� �� ������ ���� ���������, c ���� ����������
	friend ostream& operator<<(ostream&, const List&);
	void Sort();
	void DeleteAll();
	void SaveInFile();
	void ReadFromFile();
};
