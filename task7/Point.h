#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;
class Point {
	int m_x, m_y;
public:
	Point(); //����������� �� ���������
	Point(const int, const int); //����������� � �����������
	Point(const Point&); //����������� �����������
	bool operator==(const Point&); //�������� ��������� ��� �����
	bool operator<(const Point&);
	friend ostream& operator << (ostream&, const Point&);
	//friend class Rect;
	friend bool FunctionRemoveIf(Point&);
};

