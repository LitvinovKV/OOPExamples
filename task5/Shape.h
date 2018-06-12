#include "Point.h"

class Shape {
public:
	virtual double S() = 0; //������� ������
	virtual ~Shape() {};
	virtual bool operator==(Shape&) = 0; //����������� �������� ���������
	friend ostream& operator<< (ostream&, const Shape&);
};

class Rect : public Shape {
	Point m_left_top, m_right_bottom;
public:
	Rect(Point, Point); //����������� � �����������
	double S(); //������� ��������������
	bool operator==(Shape&); //����������� �������� ��������� ��� ��������������
	friend ostream& operator<< (ostream&, const Rect&);
};

class Circle : public Shape {
	Point m_x_y;
	int m_radius;
public:
	Circle(Point, int); //����������� � �����������
	double S(); //������� �����
	bool operator==(Shape&); //����������� �������� ��������� ��� �����
	friend ostream& operator<< (ostream&, const Circle&);
};