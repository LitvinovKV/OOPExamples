#include "Circle.h"


class Node {
	Node* m_pPrev;	//��������� �� ���������� �������
	Node* m_pNext;	//��������� �� ��������� �������
	Circle m_Circle;

public:
	Node();//������ ����� ����������� ��� �������� ��������������� ������� � �������� (Head, Tail)
	Node(Node*, Node*, const Circle*);	//�����������, ����������� �������� ����������� Node �������������� � ������.
	~Node();//���������� ������ ����������� ������������ Node �� ������
	friend class List;
	friend ostream& operator<<(ostream&, const Node&);
	friend ostream& operator<<(ostream&, const List&);
};
