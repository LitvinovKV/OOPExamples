// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include "Header.h"
#include "Point.h"
//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;
#define stop __asm nop

class SortForPQ {
public:
	bool operator() (const char* left, const char* right) 
	{
		if (strcmp(left, right) > 0)
			return true;
		else
			return false;
	}


};
template <typename T, typename C> void CoutAdapter(queue<T, C> my_queue) //Вывод элементов для deque
{
	while (!my_queue.empty())
	{
		cout << my_queue.front() << ' ';
		my_queue.pop();
	}
	cout << endl;
}

ostream& operator<< (ostream& out, const Point& my_point)
{
	out << "X= " << my_point.m_x << " Y= " << my_point.m_y;
	return out;
}


int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	stack<int> iStack({4, 3, 2, 1});
	CoutAdapter(iStack);

	queue<int> iQueue({ 1, 2, 3 });
	CoutAdapter(iQueue);

	priority_queue<int> iPriority_queue;
	iPriority_queue.push(10);
	iPriority_queue.push(3);
	iPriority_queue.push(6);
	iPriority_queue.push(1); 
	iPriority_queue.push(7);
	CoutAdapter(iPriority_queue);

	////////////////////////////////////////////////////////////////////////////////////
	//stack
	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	
	//a)
	vector <int> iVectorA(5, 1);
	stack <int, vector<int>> iStackA(iVectorA);
	CoutAdapter(iStackA);
	
	//b
	vector <int> iVectorB = { 1, 4, 4, 6, 11, 2 };
	stack <int, vector<int>> iStackB(vector<int>(iVectorB.rbegin(), iVectorB.rend()));
	//------------------------------------------------------------------------------------------
	cout << "Vector = "; coutContainer(iVectorB);
	cout << "Vector = "; CoutAdapter(iStackB);


	////////////////////////////////////////////////////////////////////////////////////
	//queue
	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
	{
		queue<Point*, list<Point*>> pQueue;
		pQueue.push(new Point(2, 2));
		pQueue.push(new Point(4, 4));
		
		//delete pQueue.front();
		*pQueue.front() =  Point(1, 1);
		
		delete pQueue.back();
		pQueue.back() = new Point(11, 11);
		
		while (!pQueue.empty())
		{
			delete pQueue.front();
			pQueue.pop();
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	
	const char* ar[] = {"qwerty", "abc", "abcde" };
	priority_queue<const char*, deque<const char*>, SortForPQ> cPQueue(ar, ar + 3);
	CoutAdapter(cPQueue);
	//сравниваются адреса
	//-------------------------------

	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом) 
	//      operator< const и operator==
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
	
	set<Point> pSet;
	pSet.insert(Point(1, 1)); 
	pSet.insert(Point(2, 2));
	pSet.insert(Point(2, 2));
	pSet.insert(Point(3, 3));
	coutContainer(pSet);

	//для того, чтобы изменить значение элеменита, требуется его сначала найти find(),
	//а при успехе - удалить erase() и добавить новый элемент insert();
	if (pSet.find(Point(3, 3)) != pSet.end())
	{
		pSet.erase(pSet.find(Point(3, 3)));
		pSet.insert(Point(33, 33));
	}

	set<int> setOne;
	setOne.insert(2);
	setOne.insert(4);
	setOne.insert(10);
	setOne.insert(11);
	coutContainer(setOne);
	
	set<int> setTwo;
	setTwo.insert(10);
	setTwo.insert(4);
	setTwo.insert(2);
	setTwo.insert(11);
	coutContainer(setTwo);

	int array[] = { 1, 15, 11 };
	setOne.insert(array, array + 3);
	coutContainer(setOne);

	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	
	map <const char*, int> FamSal;
	FamSal["Agapov"] = 10000;
	FamSal["Ivanova"] = 20000;
	FamSal.insert(pair<const char*, int>("Frolova", 5000));
	FamSal.insert(pair<const char*, int>("Popov", 1000));

	//в) распечатайте содержимое
	map<const char*, int>::iterator it;
	for (it = FamSal.begin(); it != FamSal.end(); it++)
		cout << (*it).first << ": " << (*it).second << endl;

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	it = FamSal.find("Ivanova");
	if (it != FamSal.end()) //если нашли
	{
		int salary = (*it).second;
		FamSal.erase(it);
		FamSal.insert(pair<const char*, int>("Petrova", salary));
	}
	stop

	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе
	
	vector<string> sVector = {"ABCD", "ABCD", "QWERT", "AAAAA", "ASDFG" , "AAAAA"};
	map<string, int> siMap;
	map<string, int>::iterator itM;
	for (int i = 0; i < sVector.size(); i++) //Цикл для прохода по вектору
	{
		siMap[sVector[i]]++;
	}

	//ВЫВОД
	cout << endl;
	for (itM = siMap.begin(); itM != siMap.end(); itM++)
		cout << (*itM).first << ": " << (*itM).second << endl;
	
	//е) 
	//задан массив:
	const char* words[] = {"Abba", "Alfa", "Beta", "Beauty", "Family", "Domo"};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки

	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	
	map<const char, set<string>> lMap;
	map<const char, set<string>>::iterator itMap;
	for (int i = 0; i < sizeof(words)/sizeof(char*); i++) //цикл для проходки по set
	{
		lMap[words[i][0]]; //добавить в список такой ключ
		lMap[words[i][0]].insert(words[i]);
	}

	//ВЫВОД
	cout << endl;
	for (itMap = lMap.begin(); itMap != lMap.end(); itMap++)
	{
		cout << (*itMap).first << ": ";
		set<string>::iterator localIT;
		for (localIT = (*itMap).second.begin(); localIT != (*itMap).second.end(); localIT++)
		{
			cout << *localIT << ' ';
		}
		cout << endl;
	}
	


	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	
	map<int, multiset<string>> mGroups;
	mGroups[123] = {"Ivanov", "Agapov"};
	mGroups[100] = { "Agapov", "Agapov", "Agapov"};
	mGroups[200] = { "Sidorov", "Vetrov"};
	mGroups[321] = { "Sovkov"};
	mGroups[300] = { "Ivanov", "Neonov" };

	cout  << "GROUPS: " << endl;
	map<int, multiset<string>>::iterator itGroups;
	multiset<string>::iterator itMS;
	
	for (itGroups = mGroups.begin(); itGroups != mGroups.end(); itGroups++)
	{
		cout << (*itGroups).first << '-';
		for (itMS = (*itGroups).second.begin(); itMS != (*itGroups).second.end(); itMS++)
		{
			cout << *itMS << ' ';
		}
		cout << endl;
	}
	

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	multimap<string, string> mmGlossary;
	mmGlossary.insert(pair<string, string>("strange", "странный"));
	mmGlossary.insert(pair<string, string>("strange", "чужой"));
	mmGlossary.insert(pair<string, string>("strange", "незнакомый"));

	mmGlossary.insert(pair<string, string>("road", "путь"));
	mmGlossary.insert(pair<string, string>("road", "дорога"));
	mmGlossary.insert(pair<string, string>("road", "шоссе"));

	mmGlossary.insert(pair<string, string>("answer", "ответ"));

	cout << "ENGLISH GLOSSARY: " << endl;
	multimap<string, string>::iterator itMM;
	for (itMM = mmGlossary.begin(); itMM !=  mmGlossary.end(); itMM++)
	{
		cout << (*itMM).first << '-' << (*itMM).second << endl;
	}

	//Поиск перевода по заданному ключу
	cout << "Введите ключ = ";
	string n = "";
	getline(cin, n);
	multimap<string, string>::iterator it_mm;
	for (it_mm = mmGlossary.lower_bound(n); it_mm != mmGlossary.upper_bound(n); ++it_mm)
	{
		cout << (*it_mm).second << endl;
	}
		stop
		system("pause");
		return 0;
}
