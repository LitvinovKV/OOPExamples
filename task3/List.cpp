#include "List.h"
List::List() {
	m_Head.m_pNext = &m_Tail;
	m_Tail.m_pPrev = &m_Head;
	m_size = 0;
}


//-----------------------------------------------------------------
List::List(const List& other_list) : List() //Конструктор копирования
{
	m_size = other_list.m_size;
	
	Node* n = other_list.m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		Circle circl = n->m_Circle;
		this->AddToTail(circl);
		n = n->m_pNext;
	}
	n = nullptr;
}

List::List(List&& other_list) : List() //Перемещающий move-конструктор
{
	m_Head.m_pNext = other_list.m_Head.m_pNext;
	other_list.m_Head.m_pNext = &m_Head;
	m_Tail.m_pPrev = other_list.m_Tail.m_pPrev;
	other_list.m_Tail.m_pPrev = &m_Tail;
	m_size = other_list.m_size;
	other_list.DeleteAll();
}

List& List::operator=(const List& other_list) //Оператор присваивания
{
	if (this != &other_list)
	{
		this->DeleteAll();
		m_size = other_list.m_size;
		Node* n = other_list.m_Head.m_pNext;
		for (size_t i = 0; i < m_size; i++)
		{
			Circle circl = n->m_Circle;
			this->AddToTail(circl);
			n = n->m_pNext;
		}
	}
	return *this;
}

List& List::operator=(List&& other_list) //перемещения
{
	this->DeleteAll();
	m_Head.m_pNext = other_list.m_Head.m_pNext;
	other_list.m_Head.m_pNext = &m_Head;
	m_Tail.m_pPrev = other_list.m_Tail.m_pPrev;
	other_list.m_Tail.m_pPrev = &m_Tail;
	m_size = other_list.m_size;
	other_list.DeleteAll();
}
//--------------------------------------------

void List::AddToHead(Circle& new_circle)
{
	Node* n = new Node(&m_Head, m_Head.m_pNext, &new_circle);
	m_size++;
}

void List::AddToTail(Circle& new_circle)
{
	Node* n = new Node(m_Tail.m_pPrev, &m_Tail, &new_circle);
	m_size++;
}

bool List::DeleteOneElement(Circle& circle_another)
{
	Node* p = m_Head.m_pNext;
	for (int i = 0; i < m_size;	i++)
	{
		if (p->m_Circle == circle_another)
		{
		/*	p->m_pPrev->m_pNext = p->m_pNext;
			p->m_pNext->m_pPrev = p->m_pPrev;
			p->m_pPrev = nullptr;
			p->m_pNext = nullptr;*/
			delete p;
			m_size--;
			return true;
		}
		p = p->m_pNext;
	}
	return false;
}

int List::DeleteElements(Circle& other_circle)
{
	int kol = 0;
	Node* p = m_Head.m_pNext;
	for (int i = 0; i < m_size; i++)
	{
		if (p->m_Circle == other_circle)
		{
			Node* n = p->m_pNext;
		/*	p->m_pPrev->m_pNext = p->m_pNext;
			p->m_pNext->m_pPrev = p->m_pPrev;
			p->m_pPrev = nullptr;
			p->m_pNext = nullptr;*/
			delete p;
			p = n;
			m_size--;
			kol++;
			continue;
		}
		p = p->m_pNext;
	}
	return kol;
}

void List::Sort()
{
	Node* n = m_Head.m_pNext; //первый элемент
	for (size_t i = 0; i < m_size; i++)
	{
		Node* m = n->m_pNext;
		for (size_t j = i + 1; j < m_size; j++)
		{
			if (m->m_Circle.S() < n->m_Circle.S())
			{
				Circle temp = m->m_Circle;
				m->m_Circle = n->m_Circle;
				n->m_Circle = temp;
			}
			m = m->m_pNext;
		}
		n = n->m_pNext;
	}
}

void List::DeleteAll()
{
	Node* n = m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
	//	if (n->m_pNext != nullptr)
		{
			Node* new_n = n->m_pNext;
			delete n;
			n = new_n;
		}
	}
	/*m_Head.m_pNext = &m_Tail;
	m_Tail.m_pPrev = &m_Head;*/
	m_size = 0;
}


void List::SaveInFile()
{
	ofstream fout("ar.txt");
	fout << *this;
	fout.close();
}

void List::ReadFromFile()
{
	ifstream file("ar.txt");
	if (!file)
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	char str[80];// = new char;
	//char str2 = new char;
	//char str3 = new char;
	int x, y, r;
	while (!(file.eof()))
	{
		file >> str >> x >> str >> y >> str >> r;
		if (strlen(str) == 0) break;
		AddToTail(Circle(Point(x, y), r));
	}
	file.close();
}
