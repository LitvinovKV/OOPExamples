#include "Point.h"

class Circle
{
	Point m_point;
	int m_radius;
public:
	Circle();
	Circle(Point, int);
	bool operator==(Circle); 
	double S(); //������� �����
	friend ostream& operator<<(ostream&, const Circle&);
};
