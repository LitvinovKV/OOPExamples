#include "List.h"

ostream& operator<< (ostream& out, const Point& my_point)
{
	out << "X= " << my_point.m_x << " Y= " << my_point.m_y;
	return out;
}

ostream& operator<<(ostream& out, const Circle& my_circle)
{
	out << my_circle.m_point << " RAD= " << my_circle.m_radius;
	return out;
}

ostream& operator<<(ostream& out, const Node& my_node)
{
	out << my_node.m_Circle;
	return out;
}


ostream& operator<<(ostream& out, const List& my_list)
{
	Node* n = my_list.m_Head.m_pNext;
	for (size_t i = 0; i < my_list.m_size; i++)
	{
		out << n->m_Circle << endl;
		n = n->m_pNext;
	}
	return out;
}

int main(){
	List l;
	l.AddToHead(Circle(Point(1, 1), 1));
	l.AddToHead(Circle(Point(3, 3), 3));
	l.AddToTail(Circle(Point(2, 2), 2));
	l.AddToHead(Circle(Point(4, 4), 4));
	l.AddToHead(Circle(Point(10, 10), 10));
	l.AddToHead(Circle(Point(1, 1), 1));
	
	//l.DeleteOneElement(Circle(Point(1, 1), 1));
	//l.DeleteElements((Circle(Point(1, 1), 1)));
	l.Sort();
	cout << l;
	
	l.SaveInFile();
	l.DeleteAll();
	l.ReadFromFile();
	cout << l;
	return 0;
}