#include "Shape.h"

class Node {
	Node* m_pPrevious;	//указатель на предыдущий элемент
	Node* m_pNext;		//указатель на следующий элемент
	Shape* m_Shape;
public:
	Node(); //Конструктор по умолчанию
	Node(Node*, Node*, Shape*); //Конструктор с параметрами
	~Node();
	friend class List;
	friend ostream& operator<< (ostream&, const Node&);
	friend ostream& operator<<(ostream&, const List&);

};

