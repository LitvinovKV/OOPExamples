//€вл€етс€ "оберткой" дл€ строки и содержит вспомогательные данные, 
//которые в частности позвол€т избежать дублировани€ данных
#include <iostream>
#include <cstring>

using namespace std;

class Counter
{
	char* m_pStr; //указатель на динамически создаваемую строку 
	unsigned int m_nOwners; //счетчик пользователей данной строки
	Counter* m_pNext; //указатель на следующий Counter
	
	//—татические переменные-------------------
	static Counter* m_Head;
	static unsigned int m_curCounters; //счетчик указателей

	//ћетоды-------------------------
	Counter(); // онструктор по умолчанию
	Counter(char*); // онструктор с параметром
	~Counter();
	void AddNewOwners(); //ƒобавить пользовател€
	void DeleteOwner(); //”брать пользовател€ 
	
	friend class MyString;
};
