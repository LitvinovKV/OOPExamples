//Стандартная библиотека шаблонов - STL 
//Контейнеры стандартной библиотеки - vector
//Итераторы

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include"Header.h"
#include"MyString.h"
#include"Point.h"

#pragma warning(disable: 4786)

using namespace std;

#define	  stop __asm nop

template<> void coutContainer(vector<Point*>& my_container)
{
	vector<Point*>::iterator it;
	cout << "Type: " << typeid(*my_container.begin()).name() << endl;
	for (it = my_container.begin(); it != my_container.end(); it++)
	{
		if (*it != nullptr)
		{
			cout << *(*it) << ' ';
			cout << endl;
		}
		
	}
}

ostream& operator<< (ostream& out, const MyString& myStr)
{
	out << myStr.m_pStr;
	return out;
}

ostream& operator<< (ostream& out, const Point& my_point)
{
	out << "X= " << my_point.m_x << " Y= " << my_point.m_y;
	return out;
}
vector<char> MyFunction(vector<char> v)
{
	vector<char>::iterator it;
	vector<char> new_vector;
	for (it = v.begin(); it != v.end(); it++)
	{
		int kol = 1;
		vector<char>::iterator jt;
		for (jt = it + 1;  jt != v.end(); jt++)
		{
			if (*it != *jt)	
				break;
			else
				kol++;	
		}
		if (kol == 1)
			new_vector.push_back(*it);

		it = it + kol - 1;
	}
	return new_vector;
}

bool FunctionRemoveIf(Point& my_point)
{
	if ((my_point.m_x < 0) || (my_point.m_y < 0))
		return true;
	else
		return false;
}

int main()
{
	// Контейнер стандартной библиотеки vector 

	//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
	
	
	vector <int> vInt(5);
	cout << "Size of vector = " << vInt.size() << endl;

	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	vInt.front() = 1;

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	for (int i = 0; i < 5; i++)
	{
		vInt.push_back(i);
		AllAboutVector(vInt);
	}
	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	
	vector<double> vDouble1(5);
	for (int i = 0; i < 5; i++)
	{
		vDouble1.push_back(i);
		AllAboutVector(vDouble1);
	}
	
	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
	
	
	vector<MyString> vMyString(5, "A");
	try
	{
		vMyString.at(2) = "Qwerty";
		vMyString[3] = "ABCD";

		//vMyString.at(10) = "asdf"; //выход за границы отловлен
		//vMyString[30] = "zxcvb"; //ошибка индекса, выход из программы
	}
	catch (const out_of_range& o)
	{
		cout << o.what() << endl;
	}
	

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
	
	vector <double> dMas;
	dMas.push_back(1);
	dMas.push_back(3);
	dMas.push_back(30);
	dMas.push_back(2.2);
	dMas.push_back(3);
	dMas.push_back(30);
	//-------------------------------------------------------
	vector<double> vDouble_new(dMas.begin(), dMas.begin() + 5);
	for (int i = 0; i < vDouble_new.size(); i++)
		cout << vDouble_new[i] << endl;
	
	
	vector <double> vDouble3;
	try
	{
		for (int i = 0; i < 5; i++)
			vDouble3.push_back(dMas.at(i));
	}
	catch (const out_of_range& o)
	{
		cout << o.what() << endl;
	}

	//Вывод
	for (int i = 0; i < vDouble3.size(); i++)
		cout << vDouble3[i] << endl;
	

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	vector <double> vDouble4;
	try
	{
		for (int i = 2; i < 5; i++)
			vDouble4.push_back(vDouble3.at(i));
	}
	catch (const out_of_range& o)
	{
		cout << o.what() << endl;
	}
	//Вывод
	for (int i = 0; i < vDouble4.size(); i++)
		cout << vDouble4[i] << endl;
	

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	
	//a - будет вызван конструктор по умолчанию
	vector <Point> vPoint1(3);
	//b
	vector <Point> vPoint2(5, Point(1,1));
	

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
	//---------------------------------------------------
		vector <Point*> vpPoint(5);
		vpPoint.push_back(new Point(2, 2)); //создаю point через new
		coutContainer(vpPoint);
		for (int i = 0; i < vpPoint.size(); i++) //Удаляю выделенную димачески память
			delete vpPoint[i];
		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*
	}	//Какие дополнительные действия нужно предпринять для такого вектора?

	 ///////////////////////////////////////////////////////////////////////
	 //Резервирование памяти.
	 //Подумайте, всегда ли верны приведенные ниже проверки?
	 
	 {
		size_t n = 5;
		vector <int> v(n);
		v.resize(n/2); //изменяет размер (count)
		if (v.capacity() == n){}
		//false
	 }
	 

	 {
		 int n = 5;
		 size_t m = 10;
		 vector<int> v(n);
		 v.reserve(m); //изменяет количество выделенной памяти (capacity)
		 if (v.capacity() == m) {} //true
	 }
	 

	 {
		 vector<int> v(3,5);
		 v.resize(4,10); //size = 4, значения 5 5 5 10
		 v.resize(5); // size = 5, значения 5 5 5 10 0
	 }
	 

	 //Создайте два "пустых" вектора с элементами
	 //любого (но одного и того же типа) типа. 
	 //В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	 //его значениями с помощью push_back.
	 //Второй вектор просто заполните значениями посредством push_back.
	 //
	 //Сравните размер, емкость векторов и значения элементов
	 
	 vector <int> vect1;
	 vect1.reserve(5);
	 vector <int> vect2;
	 AllAboutVector(vect1); //size = 0; capacity = 5
	 AllAboutVector(vect2); //size = 0; capacity = 0

	 vect1.push_back(4);
	 vect1.push_back(3);
	 vect1.push_back(66);
	 vect1.push_back(2);
	 vect1.push_back(89);

	 vect2.push_back(4);
	 vect2.push_back(3);
	 vect2.push_back(66);
	 vect2.push_back(2);
	 vect2.push_back(89);
	 AllAboutVector(vect1); //size = 5; capacity = 5
	 AllAboutVector(vect2); //size = 5; capacity = 6

	 //!!! shrink_to_fit - Уменьшение емкости вектора.
	 //Для любого вектора из предыдущего задания требуется уменьшить емкость
	 //до size.
	 vect1.shrink_to_fit();
	 vect2.shrink_to_fit();

	 AllAboutVector(vect1); //size = 5; capacity = 5
	 AllAboutVector(vect2); //size = 5; capacity = 5
	 

	 //Создание "двухмерного вектора" - вектора векторов
	 //Задан одномерный массив int ar[] = {11,2,4,3,5};
	 //Создайте вектор векторов следующим образом:
	 //вектор vv[0] - содержит 11 элементов со значением 11
	 //vv[1] - содержит 2,2
	 //vv[2] - содержит 4,4,4,4
	 //...
	 //Распечатайте содержимое такого двухмерного вектора по строкам
	 
	 
	 int ar[] = { 11,2,4,3,5 };
	 vector <vector <int>> vVect(sizeof(ar) / sizeof(int));
	 for (int i = 0; i < (sizeof(ar)/sizeof(int)); i++)
	 {
		 for (int j = 0; j < ar[i]; j++)
			vVect[i].push_back(ar[i]);
	 }

	 for (int i = 0; i < vVect.size(); i++)
	 {
		 for (int j = 0; j < vVect[i].size(); j++)
			cout << vVect[i][j] << ' ';
		 cout << endl;
	 }
	stop
	
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Вставка элемента последовательности insert().
		//В вектор vChar2 вставьте в начало вектора символ только при
		//условии, что в векторе такого еще нет.
		
		{
			vector <char> vChar2;
			vector <char>::iterator it;
			bool flag = true;
			char symbol = 'd';
			vChar2.push_back('A');
			vChar2.push_back('B');
			vChar2.push_back('C');
			for (it = vChar2.begin(); it != vChar2.end(); it++)
			{
				if (*it == symbol)
					flag = false;
			}
			if (flag == true)
			{
				it = vChar2.begin();
				vChar2.insert(it, symbol);
			}
			coutContainer(vChar2);

			//Вставьте перед каждым элементом вектора vChar2 букву 'W'
			int i = 0;
			for (it = vChar2.begin(); it != vChar2.end(); it += i)
			{
				vChar2.insert(it, 'W');
				it = vChar2.begin();
				i += 2;
			}
			coutContainer(vChar2);
		}
		


		///////////////////////////////////////////////////////////////////
		//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
		//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
		{
			vector <char> vChar3;
			vChar3.push_back('q');
			vChar3.push_back('q');
			vChar3.push_back('w');
			vChar3.push_back('e');
			vChar3.push_back('r');
			vChar3.push_back('r');
			vChar3.push_back('r');
			vChar3.push_back('t');
			vChar3.push_back('y');
			vChar3.push_back('1');
			vChar3.push_back('2');
			vChar3.push_back('2');
			vChar3.push_back('2');
			vChar3.push_back('r');
			vChar3.push_back('3');
			vChar3.push_back('3');
			vChar3 = MyFunction(vChar3);
			coutContainer(vChar3);
		}
		stop

		///////////////////////////////////////////////////////////////////
		//Удаление элемента последовательности erase()
		//Напишите функцию удаления из любого вектора всех дублей 
		
		{
			vector <char> vChar4;
			vChar4.push_back('q');
			vChar4.push_back('q');
			vChar4.push_back('w');
			vChar4.push_back('e');
			vChar4.push_back('r');
			vChar4.push_back('r');
			vChar4.push_back('r');
			vChar4.push_back('t');
			vChar4.push_back('y');
			vChar4.push_back('1');
			vChar4.push_back('2');
			vChar4.push_back('2');
			vChar4.push_back('2');
			vChar4.push_back('r');
			vChar4.push_back('3');
			DeleteSequence(vChar4);
			coutContainer(vChar4);
		}
		
		///////////////////////////////////////////////////////////////////
		//Создайте новый вектор таким образом, чтобы его элементы стали
		//копиями элементов любого из созданных ранее векторов, но расположены
		//были бы в обратном порядке
	
		{	
			vector <int> vI1;
			vI1.push_back(1);
			vI1.push_back(2);
			vI1.push_back(3);
			vI1.push_back(4);
			vector<int>vI2(vI1.rbegin(), vI1.rend());
			coutContainer(vI1);
			coutContainer(vI2);
			//-------------------------------------------------------------
			//vector<int>vI2 = InvertVector(vI1);
		}
		
		///////////////////////////////////////////////////////////////////

		//Задание 1. Списки. Операции, характерные для списков.
		//Создайте пустой список из элементов Point - ptList1 и наполните
		//его значениями с помощью методов push_back(),
		//push_front, insert()
		
		{
			list <Point> ptList1;
			ptList1.push_back(Point(1, 1));
			ptList1.push_front(Point(2, 2));
			list<Point>::iterator it = ptList1.begin();
			ptList1.insert(it, Point(3, 3));
		

		//Напишите шаблон функции, которая будет выводить элементы
		//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
		//vector и list. Подсказка - хотелось бы увидеть тип контейнера.
			vector<int> v(5, 1);
			coutContainer(ptList1);
			coutContainer(v);

		//Сделайте любой из списков "реверсивным" - reverse()
			ptList1.reverse();
			coutContainer(ptList1);

		//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
		//копией вектора элементов типа Point, но значения элементов списка располагались
		//бы в обратном порядке 
			list<Point> ptList2(ptList1.rbegin(), ptList1.rend());
			coutContainer(ptList2);
		//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
		//по возрастанию.
		//Подумайте: что должно быть перегружено в классе Point для того, чтобы
		//работала сортировка
		
			//Нужно чтобы в классе был перегружен "operator <"
			ptList1.sort();
			ptList2.sort();
			stop

		//Объедините отсортированные списки - merge(). Посмотрите: что
		//при этом происходит с каждым списком.
			ptList1.merge(ptList2);
			stop

		//Исключение элемента из списка - remove()
		//Исключите из списка элемент с определенным значением.
		//Подумайте: что должно быть перегружено в классе Point?
		//Перегрузить для класса operator == (Обязательно должен быть const входящий параметр)
			ptList1.remove(Point(2, 2));
		
		//Исключение элемента из списка, удовлетворяющего заданному условию:
		//любая из координат отрицательна - remove_if(). 
			ptList1.push_back(Point(-2, 5));
			//В качестве парметра должна передаваться ф-ия, которая возвращает bool значение
			ptList1.remove_if(FunctionRemoveIf);
		

		//Исключение из списка подряд расположенных дублей - unique().

			ptList1.push_back(Point(1, 1));
			ptList1.unique();
			stop

		///////////////////////////////////////////////////////////////////
		//Задание 2.Очередь с двумя концами - контейнер deque

		//Создайте пустой deque с элементами типа Point. С помощью
		//assign заполните deque копиями элементов вектора. С помощью
		//разработанного Вами в предыдущем задании универсального шаблона
		//выведите значения элементов на печать
			vector<Point> vPoint1 = { Point(22,1), Point(-1, 4) };
			deque<Point> qPoint;
			qPoint.assign(vPoint1.begin(), vPoint1.end());
			coutContainer(qPoint);
		//assign(какого элемента начать копировать (можно итератор на начальном элементе), 
		//			на каком элементе закончить копирование(можно итератор на последнем элементе) );

		//Создайте deque с элементами типа MyString. Заполните его значениями
		//с помощью push_back(), push_front(), insert()
		//С помощью erase удалите из deque все элементы, в которых строчки
		//начинаются с 'A' или 'a'
			deque<MyString> dMyString;
			dMyString.push_back("AAA");
			dMyString.push_front("Qwerty");
			dMyString.insert(dMyString.begin(), "abcd");
			deque<MyString>::iterator itt = dMyString.begin();
			while (itt != dMyString.end())
			{
				if ((**itt[0] == 'a') || (**itt[0] == 'A'))
				{
					itt = dMyString.erase(itt);
				}
				else
				{
					itt++;
				}
			}
			coutContainer(dMyString);
		}
		//-----------------------------------------------------------
		system("pause");
		return 0;
}