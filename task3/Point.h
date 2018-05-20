#include <iostream>
using namespace std;

class Point
{
	int m_x;
	int m_y;
public:
	Point();
	Point(int, int);
	bool operator==(Point);
	friend ostream& operator<< (ostream&, const Point&);
};
