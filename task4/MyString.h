#include "Counter.h"

class MyString {
	Counter* m_pMyCounter; //указатель на "свой" Counter 
public:
	
	MyString(); //Конструктор по умолчанию
	MyString(char*); //Конструктор с параметром
	~MyString();
	
	//Джентельменский набор: 
	MyString(MyString&);//Конструктор копирования
	MyString(MyString&&); //Перемещающий move-конструктор &&
	MyString& operator= (MyString&); //Оператор присваивания operator=
	MyString& operator= (MyString&&); //Перемещения operator=&&

	static void PrintAll();
	static void Sorting();
	static void EditRegister();
};
