#include "Counter.h"
Counter* Counter::m_Head = new Counter();
unsigned int Counter::m_curCounters = 0;

Counter::Counter()
{
	m_pStr = nullptr;
	m_nOwners = 0;
	m_pNext = nullptr;
}

Counter::~Counter()
{
	Counter* p = m_Head;
	for (size_t i = 0; i < m_curCounters; i++)
	{
		if (p->m_pNext == this)
			p->m_pNext = this->m_pNext; 
		p = p->m_pNext; 
	}
	delete[] m_pStr; 
	m_nOwners = 0;
	m_pNext = nullptr;
	m_curCounters--;
	if (m_curCounters == 0) {
		delete m_Head;
		m_Head = nullptr;
	}
}

Counter::Counter(char* char_str)
{
	m_pStr = new char[strlen(char_str) + 1];
	strcpy(m_pStr, char_str);
	m_nOwners++;
	m_curCounters++;

}

void Counter::AddNewOwners() 
{
	m_nOwners++;
}

void Counter::DeleteOwner() 
{
	m_nOwners--;
	if (m_nOwners == 0) 
	{
		delete this;
	}	
}