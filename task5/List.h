#include "Node.h"
class List {
	Node m_Head;	// фиктивный элемент, который €вл€етс€ признаком начала списка
	Node m_Tail;	// фиктивный элемент, который €вл€етс€ признаком конца списка
	unsigned int m_size;	//количество элементов
public:
	List(); //сформировать Head, Tail и m_size 

	//Ќабор -------------
	List& operator=(const List&); //ќператор присваивани€
	List(const List&); // онструктор копировани€
	List(List&&); //move-конструктор
	List& operator=(List&&); //перемещени€
	//------------------------

	void AddToHead(Shape&); //метод, который добавл€ет элемент в начало списка
	void AddToTail(Shape&); //добавл€ет элемент в конец списка
	
	bool DeleteOneElement(Shape&); //удаление из списка 1ого элемента, c совпадающим параметром
	int DeleteElements(Shape&); //удаление из списка всех элементов, c совп параметром
	friend ostream& operator<<(ostream&, const List&);
	void Sort();
	void DeleteAll();
	void SaveInFile();
	void ReadFromFile();
};
