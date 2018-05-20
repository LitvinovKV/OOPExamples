#include "Point.h"

Point::Point() {}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

bool Point::operator==(Point other_point)
{
	return(m_x == other_point.m_x && m_y == other_point.m_y);
}