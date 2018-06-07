#include "MyString.h"

MyString::MyString()
{
	m_pMyCounter = nullptr;
}

MyString::~MyString()
{
	if (m_pMyCounter != 0)
	{
		//delete m_pMyCounter;
		m_pMyCounter->DeleteOwner();
		m_pMyCounter = nullptr;
	}
	else
		m_pMyCounter = nullptr;
	
}

MyString::MyString(MyString& other_string)
{
	m_pMyCounter = nullptr;
	if (other_string.m_pMyCounter!= nullptr)
	{
		m_pMyCounter = other_string.m_pMyCounter;
		m_pMyCounter->m_nOwners++;
	}
}

MyString::MyString(MyString&& other_string)
{
	m_pMyCounter = nullptr;
	if (other_string.m_pMyCounter != nullptr)
	{
		m_pMyCounter = other_string.m_pMyCounter;
		other_string.m_pMyCounter = nullptr;
	}
}

MyString& MyString::operator=(MyString& other_string)
{
	if (m_pMyCounter != other_string.m_pMyCounter)
	{
		if (m_pMyCounter != nullptr) 
			m_pMyCounter->DeleteOwner();
		m_pMyCounter = other_string.m_pMyCounter;
		if (other_string.m_pMyCounter != nullptr)
		{			
			m_pMyCounter->m_nOwners++; 
		}
	}
	return *this;
}

MyString& MyString::operator= (MyString&& other_string)
{
	
		if (m_pMyCounter != other_string.m_pMyCounter)
		{
			if (m_pMyCounter != nullptr) 
				m_pMyCounter->DeleteOwner();
			m_pMyCounter = other_string.m_pMyCounter;
			other_string.m_pMyCounter = nullptr;
		}

	return *this;
}

MyString::MyString(char* p) 
{
	if (Counter::m_Head == nullptr) {
		Counter::m_Head = new Counter();
		Counter::m_curCounters = 0;
	}
	Counter* c = Counter::m_Head->m_pNext;
	for (unsigned int i = 0; i < Counter::m_curCounters; i++)
	{
		if (strcmp(p, c->m_pStr) == 0)
		{
			c->AddNewOwners();
			m_pMyCounter = c;
			return;
		}
		c = c->m_pNext;
	}
	
	Counter* new_count = new Counter(p);
	new_count->m_pNext = Counter::m_Head->m_pNext;
	Counter::m_Head->m_pNext = new_count;
	m_pMyCounter = new_count;

}

void MyString::PrintAll()
{
	if (Counter::m_Head->m_pNext == nullptr) return;
	Counter* p = Counter::m_Head->m_pNext;
	for (size_t i = 0; i < Counter::m_curCounters; i++)
	{
		cout << "STR = " << p->m_pStr << "  OWNERS = " << p->m_nOwners << endl;
		p = p->m_pNext;
	}
}

void MyString::Sorting()
{
	Counter* p = Counter::m_Head;
	for (size_t i = 0; i < Counter::m_curCounters - 1; i++)
	{
		Counter* p_1 = p->m_pNext->m_pNext;
		Counter* p_1_prev = p->m_pNext;
		while(p_1 != nullptr) {
			// Если поменять местами листья-соседей
			if (strcmp(p->m_pNext->m_pStr, p_1->m_pStr) > 0) {
				if (p->m_pNext->m_pNext == p_1) {
					p->m_pNext->m_pNext = p_1->m_pNext;
					p_1->m_pNext = p->m_pNext;
					p->m_pNext = p_1;
					p_1_prev = p_1;
					p_1 = p_1->m_pNext;
				}
				//Иначе поменять местами листья, между которыми находится n листьев
				else {
					Counter* tmp = p_1->m_pNext;
					p_1_prev->m_pNext = p->m_pNext;
					p_1->m_pNext = p->m_pNext->m_pNext;
					p->m_pNext->m_pNext = tmp;
					p->m_pNext = p_1;
					p_1 = p_1_prev->m_pNext;
				}
			}
			p_1_prev = p_1;
			p_1 = p_1->m_pNext;
		}
		p = p->m_pNext;
	}
}

void MyString::EditRegister()
{
	Counter* p = Counter::m_Head->m_pNext;
	for (size_t i = 0; i < Counter::m_curCounters; i++)
	{
		for (size_t j = 0; j < strlen(p->m_pStr); j++)
		{
			if ((int(p->m_pStr[j]) > 96) && (int(p->m_pStr[j]) < 123))
			{
				p->m_pStr[j] = char(int(p->m_pStr[j]) - 32);
			}
			else if ((int(p->m_pStr[j]) > 64) && (int(p->m_pStr[j]) < 91))
			{
				p->m_pStr[j] = char(int(p->m_pStr[j]) + 32);
			}
		}
		p = p->m_pNext;
	}
}