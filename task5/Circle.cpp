#include "Shape.h"
Circle::Circle(Point p, int rad) : m_x_y(p), m_radius(rad) //Конструктор с параметрами
{
}

double Circle::S() //Площадь круга
{
	return (m_radius * m_radius * 3.14);
}

bool Circle::operator==(Shape& other_shape) //Виртуальный оператор сравнения для круга
{
	//Circle* pC = dynamic_cast<Circle*>(&other_shape);
	if (Circle* pC = dynamic_cast<Circle*>(&other_shape))
	{
		if ((m_radius == pC->m_radius) && (m_x_y == pC->m_x_y))
			return true;
		else
			return false;
	}
	else
		return false;
}