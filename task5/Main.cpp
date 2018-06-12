#include "List.h"


ostream& operator<< (ostream& out, const Point& my_point)
{
	out << "X= " << my_point.m_x << " Y= " << my_point.m_y;
	return out;
}

ostream& operator<< (ostream& out, const Shape& my_shape)
{
	if (const Rect* pR = dynamic_cast<const Rect*>(&my_shape))
		out << *pR << endl;
	else if (const Circle* pC = dynamic_cast<const Circle*>(&my_shape))
		out << *pC << endl;
	return out;
}
ostream& operator<<(ostream& out, const Circle& my_circle)
{
	out << my_circle.m_x_y << " RAD= " << my_circle.m_radius;
	return out;
}

ostream& operator<<(ostream& out, const Rect& my_rect)
{
	out << my_rect.m_left_top << "  " << my_rect.m_right_bottom;
	return out;
}

ostream& operator<<(ostream& out, const Node& my_node)
{
	out << my_node.m_Shape;
	return out;
}

ostream& operator<<(ostream& out, const List& my_list)
{
	Node* n = my_list.m_Head.m_pNext;
	for (size_t i = 0; i < my_list.m_size; i++)
	{
		out << *n->m_Shape;
		n = n->m_pNext;
	}
	return out;
}
int main() {

	List l1;
	l1.AddToTail(Rect(Point(2, 3), Point(4, 5)));
	l1.AddToHead(Circle(Point(6, 7), 8));
	l1.AddToTail(Rect(Point(2000, 3), Point(4, 5)));
	
	/*List l2;
	l2 = l1;*/
	
	cout << l1;
	l1.Sort();
	
	cout << "\n";
	cout << l1;
	
	l1.DeleteElements(Rect(Point(2, 3), Point(4, 5)));
	cout << "\n";
	cout << l1;

	l1.SaveInFile();
	l1.DeleteAll();
		
	l1.ReadFromFile();
	cout << "\n";
	cout << l1 ;
	system("pause");
	return 0;
}