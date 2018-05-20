#include "Node.h"
#include <fstream>

class List {
	Node m_Head;	// фиктивный элемент, который является признаком начала списка
	Node m_Tail;	// фиктивный элемент, который является признаком конца списка
	unsigned int m_size;	//количество элементов
public:
	List(); //сформировать Head, Tail и m_size 

	//Реализовать -------------
	List& operator=(const List&); //Оператор присваивания
	List(const List&); //Конструктор копирования
	List(List&&); //move-конструктор
	List& operator=(List&&); //перемещения

	//------------------------

	void AddToHead(Circle&); //метод, который добавляет элемент в начало списка
	void AddToTail(Circle&); //метод, который добавляет элемент в конец списка
	bool DeleteOneElement(Circle&); //удаление из списка 1ого элемента, c совпадающим параметром
	int DeleteElements(Circle&); //удаление из списка всех элементов, c совп параметром
	friend ostream& operator<<(ostream&, const List&);
	void Sort();
	void DeleteAll();
	void SaveInFile();
	void ReadFromFile();
};

