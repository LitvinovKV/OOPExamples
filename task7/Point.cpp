#include "Point.h"

Point::Point() : m_x(0), m_y(0) // ѕо умолчанию
{
	//m_x = 0;
	//m_y = 0;
}

Point::Point(const int x, const int y) // онструктор с параметрами
{
	m_x = x;
	m_y = y;
}

Point::Point(const Point& other_point) // онструктор копировани€
{
	m_x = other_point.m_x;
	m_y = other_point.m_y;
}

bool Point::operator==(const Point& other_point) //ќператор равенства дл€ точки
{
	if ((m_x == other_point.m_x) && (m_y == other_point.m_y))
		return true;
	else
		return false;
}

bool Point::operator<(const Point& other_point) {
	//≈сли по оси "x" отрицательна
	if (m_x < other_point.m_x) 
		return true;
	else if (m_x == other_point.m_x) 
	{ //иначе если равны, то сравнить по оси "y"
		if (m_y < other_point.m_y) 
			return true; //если по оси "y" отрицательна или равна
		else 
			return false;
	}
	else 
		return false;
}