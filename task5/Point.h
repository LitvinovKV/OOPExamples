#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;
class Point {
	int m_x, m_y;
public:
	Point(int, int); //����������� � �����������
	Point(Point&); //����������� �����������
	bool operator==(Point&); //�������� ��������� ��� �����
	friend ostream& operator<< (ostream&, const Point&);
	friend class Rect;
};
