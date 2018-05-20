#include "Node.h"

Node::Node() 
{
	m_pPrev = nullptr;
	m_pNext = nullptr;
}

Node::Node(Node* prev, Node* next, const Circle* pcir) : m_Circle(*pcir)
{
	//Установить указатели на соседей
	m_pPrev = prev;
	m_pNext = next;
	
	//Устанавливаем указатели у соседей на наш Node
	if (prev != 0) 
		prev->m_pNext = this;
	if (next != 0)
		next->m_pPrev = this;
}

Node::~Node()
{
	if (m_pNext != 0)
		m_pNext->m_pPrev = m_pPrev;
	if (m_pPrev != 0)
		m_pPrev->m_pNext = m_pNext;
	//m_pNext = nullptr; --------
	//m_pPrev = nullptr;
}