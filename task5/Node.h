#include "Shape.h"

class Node {
	Node* m_pPrevious;	//��������� �� ���������� �������
	Node* m_pNext;		//��������� �� ��������� �������
	Shape* m_Shape;
public:
	Node(); //����������� �� ���������
	Node(Node*, Node*, Shape*); //����������� � �����������
	~Node();
	friend class List;
	friend ostream& operator<< (ostream&, const Node&);
	friend ostream& operator<<(ostream&, const List&);

};

