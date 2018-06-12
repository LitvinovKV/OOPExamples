#include "Node.h"

Node::Node() //Конструктор по умолчанию
{
	m_pNext = nullptr;
	m_pPrevious = nullptr;
	m_Shape = nullptr;
}

Node::Node(Node* next, Node* prev, Shape* shap) //Конструктор с параметрами
{
	m_pPrevious = prev;
	m_pNext = next;
	
	if (prev != 0) //Если есть предыдущий элемент
		prev->m_pNext = this;
	if (next != 0) //Если есть следующий элемент
		next->m_pPrevious = this;

	if (Rect* pR = dynamic_cast<Rect*>(shap)) //Если это прямоугольник
		m_Shape = new Rect(*pR);
	else if (Circle* pC = dynamic_cast<Circle*>(shap)) //Если пришел круг
		// m_Shape = new Circle(dynamic_cast<Circle*>(shap));
		m_Shape = new Circle(*pC);
}

Node::~Node() //Деструктор
{
	if (m_pNext != 0)
		m_pNext->m_pPrevious = m_pPrevious;
	if (m_pPrevious != 0)
		m_pPrevious->m_pNext = m_pNext;
	delete m_Shape;
}