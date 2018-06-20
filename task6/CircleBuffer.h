#include <stdexcept>
using namespace std;

template <typename T, int capacity> 
class CircleBuffer {
	T* m_array;
	int m_FirstIndex;
	int m_LastIndex;
	int m_capacity;
	int m_count;
public:
	CircleBuffer(); //����������� �� ���������
	~CircleBuffer(); //����������
	CircleBuffer(const CircleBuffer&); //����������� �����������
	CircleBuffer(CircleBuffer&&); //Move-����������p
	CircleBuffer& operator=(const CircleBuffer&); //���������� operator= ���������� 
	CircleBuffer& operator=(CircleBuffer&&); //Move operator=

	//������
	void Push(const T&); //��������
	void Pop(); //�������
	void ResizeBuffer(const int); //�������� ������
	template <typename T, int capacity>  friend ostream& operator <<  (ostream&, CircleBuffer<T, capacity>&);

};

template <typename T, int capacity> CircleBuffer<T, capacity>::CircleBuffer() //����������� �� ���������
{
	m_capacity = capacity;
	m_count = 0;
	m_array = new T[m_capacity];
	m_FirstIndex = 0;
	m_LastIndex = 0;
}

template <typename T, int capacity> CircleBuffer<T, capacity>::~CircleBuffer() //����������
{
	delete[] m_array;
	m_array = nullptr;
	m_FirstIndex = 0;
	m_LastIndex = 0;
	m_capacity = 0;
	m_count = 0;
}


template <typename T, int capacity> 
CircleBuffer<T, capacity>::CircleBuffer(const CircleBuffer& other_buffer) : CircleBuffer()
{
	for (int j = 0; j < other_buffer.m_count; j++)
	{
		int i = (other_buffer.m_FirstIndex + j) % other_buffer.m_capacity;
		m_array[j] = other_buffer.m_array[i];
	}
	m_count = other_buffer.m_count;
	m_capacity = other_buffer.m_capacity;
	m_FirstIndex = 0;
	m_LastIndex = (m_FirstIndex + m_count) % m_capacity;
}

template <typename T, int capacity> 
CircleBuffer<T, capacity>::CircleBuffer(CircleBuffer&& other_buffer) : CircleBuffer()
{
	m_array = other_buffer.m_array;
	m_count = other_buffer.m_count;
	m_capacity = other_buffer.m_capacity;
	m_FirstIndex = 0;
	m_LastIndex = other_buffer.m_LastIndex;
	other_buffer.m_array = nullptr;
}

template <typename T, int capacity>
CircleBuffer<T, capacity>& CircleBuffer<T, capacity>::operator= (const CircleBuffer& other_buffer)
{
	if (&other_buffer != this)
	{
		for (int j = 0; j < other_buffer.m_count; j++)
		{
			int i = (other_buffer.m_FirstIndex + j) % other_buffer.m_capacity;
			m_array[j] = other_buffer.m_array[i];
		}
		m_count = other_buffer.m_count;
		m_capacity = other_buffer.m_capacity;
		m_FirstIndex = 0;
		m_LastIndex = (m_FirstIndex + m_count) % m_capacity;
	}
	return *this;
}

template <typename T, int capacity>
CircleBuffer<T, capacity>& CircleBuffer<T, capacity>::operator=(CircleBuffer&& other_buffer)
{
	if (&other_buffer != this)
	{
		delete []this->m_array; //----------
		m_array = other_buffer.m_array;
		m_count = other_buffer.m_count;
		m_capacity = other_buffer.m_capacity;
		m_FirstIndex = 0;
		m_LastIndex = other_buffer.m_LastIndex;
		//other_buffer.~CircleBuffer();
		other_buffer.m_array = nullptr;
		other_buffer.m_count = 0;
	}
	return *this;
}

//***********************************************************************************
template <typename T, int capacity> void CircleBuffer<T, capacity>::Push(const T& other_data)
{
	if (m_count < m_capacity) 
	{
		m_array[m_LastIndex] = other_data;
		m_count++;
		m_LastIndex = (m_FirstIndex + m_count) % m_capacity;
	}
	else
		throw out_of_range("Alert!"); 
}

template <typename T, int capacity> void CircleBuffer<T, capacity>::Pop() 
{
	if (m_count != 0)
	{
		m_FirstIndex = (++m_FirstIndex) % m_capacity;
		m_count--;
	}
	else
		throw out_of_range("Alert!");
}

template <typename T, int capacity> void CircleBuffer<T, capacity>::ResizeBuffer(const int new_size)
{
	T* new_array = new T[new_size];
	int i = 0;
	for (int j = 0; j < m_count; j++)
	{
		i = (m_FirstIndex + j) % m_capacity;
		new_array[j] = m_array[i];
	}
	m_capacity = new_size;
	m_FirstIndex = 0;
	m_LastIndex = (m_FirstIndex + m_count) % m_capacity;  

	delete[] m_array;
	m_array = new_array;
	new_array = nullptr;
}

template <typename T, int capacity> 
ostream& operator<< (ostream& out, CircleBuffer<T, capacity>& buffer)
{
	for (int j = 0; j < buffer.m_count; j++)
	{
		int i = (buffer.m_FirstIndex + j) % buffer.m_capacity;
		out << buffer.m_array[i] << ' ';
	}
	return out;
}
