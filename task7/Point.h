#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;
class Point {
	int m_x, m_y;
public:
	Point(); //Конструктор по умолчанию
	Point(const int, const int); //Конструктор с параметрами
	Point(const Point&); //Конструктор копирования
	bool operator==(const Point&); //Оператор равенства для точки
	bool operator<(const Point&);
	friend ostream& operator << (ostream&, const Point&);
	//friend class Rect;
	friend bool FunctionRemoveIf(Point&);
};

