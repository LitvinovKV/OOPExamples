#include "Point.h"

class Shape {
public:
	virtual double S() = 0; //Площадь фигуры
	virtual ~Shape() {};
	virtual bool operator==(Shape&) = 0; //Виртуальный оператор сравнения
	friend ostream& operator<< (ostream&, const Shape&);
};

class Rect : public Shape {
	Point m_left_top, m_right_bottom;
public:
	Rect(Point, Point); //Конструктор с параметрами
	double S(); //Площадь прямоугольника
	bool operator==(Shape&); //Виртуальный оператор сравнения для прямоугольника
	friend ostream& operator<< (ostream&, const Rect&);
};

class Circle : public Shape {
	Point m_x_y;
	int m_radius;
public:
	Circle(Point, int); //Конструктор с параметрами
	double S(); //Площадь круга
	bool operator==(Shape&); //Виртуальный оператор сравнения для круга
	friend ostream& operator<< (ostream&, const Circle&);
};