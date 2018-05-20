#include "Circle.h"


class Node {
	Node* m_pPrev;	//указатель на предыдущий элемент
	Node* m_pNext;	//указатель на следующий элемент
	Circle m_Circle;

public:
	Node();//скорее всего понадобитс€ дл€ создани€ вспомогательных оберток Ц Ђстражейї (Head, Tail)
	Node(Node*, Node*, const Circle*);	//конструктор, посредством которого создаваемый Node Ђподключаетс€ї в список.
	~Node();//деструктор должен Ђисключатьї уничтожаемый Node из списка
	friend class List;
	friend ostream& operator<<(ostream&, const Node&);
	friend ostream& operator<<(ostream&, const List&);
};
