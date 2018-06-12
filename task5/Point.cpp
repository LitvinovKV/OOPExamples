#include "Point.h"
Point::Point(int x, int y) //Конструктор с параметрами
{
	m_x = x;
	m_y = y;
}

Point::Point(Point& other_point) //Конструктор копирования
{
	m_x = other_point.m_x;
	m_y = other_point.m_y;
}

bool Point::operator==(Point& other_point) //Оператор равенства для точки
{
	if ((m_x == other_point.m_x) && (m_y == other_point.m_y))
		return true;
	else
		return false;
}