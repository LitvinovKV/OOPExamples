#include "Point.h"
Point::Point(int x, int y) //����������� � �����������
{
	m_x = x;
	m_y = y;
}

Point::Point(Point& other_point) //����������� �����������
{
	m_x = other_point.m_x;
	m_y = other_point.m_y;
}

bool Point::operator==(Point& other_point) //�������� ��������� ��� �����
{
	if ((m_x == other_point.m_x) && (m_y == other_point.m_y))
		return true;
	else
		return false;
}