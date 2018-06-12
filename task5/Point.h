#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;
class Point {
	int m_x, m_y;
public:
	Point(int, int); //Конструктор с параметрами
	Point(Point&); //Конструктор копирования
	bool operator==(Point&); //Оператор равенства для точки
	friend ostream& operator<< (ostream&, const Point&);
	friend class Rect;
};
