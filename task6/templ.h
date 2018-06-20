#include <stdexcept>

using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1 ------------------------------------------------------------------------------------
template <typename T, const int size> 
class MyStack {
	T m_arr[size];
	int m_count;
public:
	MyStack();
	T& operator[](int);
	bool Push(const T&);
	bool Pop();
};

template <typename T, int size>  MyStack<T, size>::MyStack() 
{
	for (size_t i = 0; i < size; i++)
		m_arr[i] = T();
	m_count = 0;
}

template <typename T, int size> T& MyStack<T, size>:: operator[](int i) //operator[]
{
	if (i > 0 && i < count)
		return m_arr[i];
	else
		throw out_of_range("Alert!");
}

template <typename T, int size> bool MyStack<T, size>::Push(const T& new_element) 
{
	if (m_count <= size)
	{
		m_arr[m_count] = new_element;
		m_count++;
		return true;
	}
	else
		throw out_of_range("Out of range");
}

template <typename T, int size> bool MyStack<T, size>::Pop()
{
	if (m_count != 0) 
	{
		m_count--;
		return true;
	}
	else
		throw out_of_range("Out of range");
}