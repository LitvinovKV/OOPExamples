#include "Point.h"

Point::Point() : m_x(0), m_y(0) // По умолчанию
{
	//m_x = 0;
	//m_y = 0;
}

Point::Point(const int x, const int y) //Конструктор с параметрами
{
	m_x = x;
	m_y = y;
}

Point::Point(const Point& other_point) //Конструктор копирования
{
	m_x = other_point.m_x;
	m_y = other_point.m_y;
}

bool Point::operator==(const Point& other_point) //Оператор равенства для точки
{
	if ((m_x == other_point.m_x) && (m_y == other_point.m_y))
		return true;
	else
		return false;
}

bool Point::operator<(const Point& other_point) const 
{
	if (m_x < other_point.m_x)
		return true;
	else if (m_x == other_point.m_x)
	{
		if (m_y < other_point.m_y)
			return true;
		else
			return false;
	}
	else return false;
}