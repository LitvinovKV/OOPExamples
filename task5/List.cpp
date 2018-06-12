#include "List.h"

List::List() //����������� �� ��������� - ������������ Head, Tail � m_size 
{
	m_Head.m_pNext = &m_Tail;
	m_Tail.m_pPrevious = &m_Head;
	m_size = 0;
}

//----------------------------NABOR--------------------------------
List& List::operator=(const List& other_list) //�������� ������������
{
	if (this != &other_list)
	{
		this->DeleteAll();
		m_size = other_list.m_size;
		Node* n = other_list.m_Head.m_pNext;
		for (size_t i = 0; i < other_list.m_size; i++)
		{
			AddToTail(*n->m_Shape);
			n = n->m_pNext;
		}
	}
	return *this;
}

List::List(const List& other_list) : List() //����������� �����������
{
	m_size = other_list.m_size;
	Node* n = other_list.m_Head.m_pNext;
	for (size_t i = 0; i < other_list.m_size; i++)
	{
		AddToTail(*n->m_Shape);
		n = n->m_pNext;
	}
}

List::List(List&& other_list) //move-�����������
{
	m_size = other_list.m_size;
	
	//�������������� ���������
	m_Head.m_pNext = other_list.m_Head.m_pNext;
	other_list.m_Head.m_pNext = &m_Head;
	m_Tail.m_pPrevious = other_list.m_Tail.m_pPrevious;
	other_list.m_Tail.m_pPrevious = &m_Tail;
	
	other_list.m_Head.m_pNext = &other_list.m_Tail;
	other_list.m_Tail.m_pPrevious = &other_list.m_Head;
}

List& List::operator=(List&& other_list) //�����������
{
	if (this != &other_list)
	{
		this->DeleteAll();
		m_Head.m_pNext = other_list.m_Head.m_pNext;
		other_list.m_Head.m_pNext = &m_Head;
		m_Tail.m_pPrevious = other_list.m_Tail.m_pPrevious;
		other_list.m_Tail.m_pPrevious = &m_Tail;

		m_size = other_list.m_size;
		//---------------------------------------
		other_list.m_Head.m_pNext = &other_list.m_Tail;
		other_list.m_Tail.m_pPrevious = &other_list.m_Head;
	}
	return *this;
}
//---------------------------------------------------


void List::AddToHead(Shape& new_shape) //�����, ������� ��������� ������� � ������ ������
{
	Node* n = new Node(m_Head.m_pNext, &m_Head, &new_shape);
	m_size++;
}

void List::AddToTail(Shape& new_shape) //�����, ������� ��������� ������� � ����� ������
{
	Node* n = new Node(&m_Tail, m_Tail.m_pPrevious,  &new_shape);
	m_size++;
}

void List::DeleteAll()
{
	Node* n = m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		Node* new_n = n->m_pNext;
		delete n;
		n = new_n;
	}
	m_size = 0;
}

bool List::DeleteOneElement(Shape& other_shape) //�������� �� ������ 1��� ��������, c ����������� ����������
{
	Node* n = m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		//if (typeid(other_shape).name() == typeid(*n->m_Shape).name()) //���� ��� ��������� ������ ����� �� ��� � ������ �� ������
		//{
			if (*n->m_Shape == other_shape)
			{
				delete n;
				m_size--;
				return true;
			}
		//}
		n = n->m_pNext;
	}
	return false;
}

int List::DeleteElements(Shape& other_shape) //�������� �� ������ ���� ���������, c ���� ����������
{
	int kol = 0;
	Node* n = m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		//if (typeid(other_shape).name() == typeid(*n->m_Shape).name()) //���� ��� ��������� ������ ����� �� ��� � ������ �� ������
		//{
			if (*n->m_Shape == other_shape)
			{
				Node* new_node = n->m_pNext;
				delete n;
				//m_size--;
				kol++;
				n = new_node;
				continue;
			}
		//}
		n = n->m_pNext;
	}
	m_size -= kol;
	return kol;
}

void List::Sort()
{
	Node* n = m_Head.m_pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		Node* m = n->m_pNext;
		for (size_t j = i + 1; j < m_size; j++)
		{
			if (n->m_Shape->S() < m->m_Shape->S())
			{
				Shape* temp = m->m_Shape;
				m->m_Shape = n->m_Shape;
				n->m_Shape = temp;
				temp = nullptr;
			}
			m = m->m_pNext;
		}
		n = n->m_pNext;
	}
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
		cout << "���� �� ������!" << endl;
		return;
	}
	char str[20];
	int x, y, r, q;
	while (!(file.eof()))
	{
		file >> str >> x >> str >> y >> str >> r;
		if (strlen(str) == 0) break;
		if (strcmp("RAD=", str) == 0) {
			AddToTail(Circle(Point(x, y), r));
		}
		else {
			file >> str >> q;
			AddToTail(Rect(Point(x, y), Point(r, q)));
		}
	}
	file.close();
}