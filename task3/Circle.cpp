#include "Circle.h"

Circle::Circle() {}

Circle::Circle(Point p, int rad) : m_point(p)
{
	m_radius = rad;
}

bool Circle::operator==(Circle other_circle)
{
	return(m_point == other_circle.m_point && m_radius == other_circle.m_radius);
}

double Circle::S()
{
	return 3.14 * m_radius * m_radius;
}