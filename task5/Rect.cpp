#include "Shape.h"

Rect::Rect(Point left_top, Point right_bottom) : m_left_top(left_top), m_right_bottom(right_bottom) //Конструктор с параметрами
{
}

double Rect::S()  //Площадь прямоугольника
{
	return (m_right_bottom.m_x - m_left_top.m_x) * (m_left_top.m_y - m_right_bottom.m_y);
}

bool Rect::operator==(Shape& other_shape) //Виртуальный оператор сравнения для прямоугольника
{
	//Rect* pR = dynamic_cast<Rect*>(&other_shape);
	if (Rect* pR = dynamic_cast<Rect*>(&other_shape))
	{
		if ((m_left_top == pR->m_left_top) && (m_right_bottom == pR->m_right_bottom))
			return true;
		else
			return false;
	}
	else
		return false;
	
}