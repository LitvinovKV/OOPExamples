#include "NodeTempl.h"

template<typename T>
class MyStack_2 {
	Node<T> m_Head;
	int m_count;
	void RecursionMyStack_2(Node<T>&); 
	void ClearList(Node<T>*); 
	void RecursionForConstructor(Node<T>&); 
public:
	MyStack_2();
	~MyStack_2();
	void Push(const T&); 
	void CoutMyStack_2(); 
	MyStack_2(const MyStack_2&);
	MyStack_2(MyStack_2&&); 
	MyStack_2& operator= (MyStack_2&); 
	MyStack_2& operator= (MyStack_2&&); 
};


template <typename T> MyStack_2<T>::MyStack_2() 
{
	m_count = 0;
}


template <typename T> MyStack_2<T>::~MyStack_2() 
{
	if (m_Head.m_pNext != nullptr)
		ClearList(m_Head.m_pNext);
	m_Head.m_pNext = nullptr;
	m_count = 0;
}

template <typename T> MyStack_2<T>::MyStack_2(const MyStack_2& other_stack_2) : MyStack_2()
{
	if (other_stack_2.m_Head.m_pNext != nullptr)
		RecursionForConstructor(*other_stack_2.m_Head.m_pNext);
	m_count = other_stack_2.m_count;
}


template <typename T> MyStack_2<T>::MyStack_2(MyStack_2&& other_stack_2) : MyStack_2()
{
	m_Head.m_pNext = other_stack_2.m_Head.m_pNext;
	other_stack_2.m_Head.m_pNext = nullptr;
	m_count = other_stack_2.m_count;
	other_stack_2.m_count = 0;
}

template <typename T> MyStack_2<T>& MyStack_2<T>::operator=(MyStack_2& other_stack_2)
{
	if (&other_stack_2 != this)
	{
		this->~MyStack_2();
		if (other_stack_2.m_Head.m_pNext != nullptr)
			RecursionForConstructor(*other_stack_2.m_Head.m_pNext);
		m_count = other_stack_2.m_count;
	}
	return *this;
}

template <typename T> MyStack_2<T>& MyStack_2<T>::operator=(MyStack_2&& other_stack_2)
{
	if (&other_stack_2 != this)
	{
		this->~MyStack_2();
		m_Head.m_pNext = other_stack_2.m_Head.m_pNext;
		m_count = other_stack_2.m_count;
		other_stack_2.m_Head.m_pNext = nullptr;
		other_stack_2.m_count = 0;
		
		//other_stack_2.~MyStack_2(); //----
	}
	return *this;
}
//-------------------METHODS-------------------------------------------

template <typename T> void MyStack_2<T>::Push(const T& other_data)
{
	Node<T>* n = new Node<T>(m_Head.m_pNext, other_data);
	m_Head.m_pNext = n;
	m_count++;
}

template <typename T> void MyStack_2<T>::ClearList(Node<T>* my_node)
{
	if (my_node->m_pNext != nullptr)
		ClearList(my_node->m_pNext);
	delete my_node;
	return;
}

template <typename T> void MyStack_2<T>::RecursionMyStack_2(Node<T>& my_node)
{
	if (my_node.m_pNext != nullptr)
		RecursionMyStack_2(*my_node.m_pNext);
	cout << *my_node.m_pData << endl;
	return;
}

template <typename T> void MyStack_2<T>::CoutMyStack_2() //COUT
{
	if (m_Head.m_pNext != nullptr)
		RecursionMyStack_2(*m_Head.m_pNext);
	else
		cout << "MyStack_2 is empty!" << endl;
}

template <typename T> void MyStack_2<T>::RecursionForConstructor(Node<T>& other_node)
{
	if (other_node.m_pNext != nullptr)
		RecursionForConstructor(*other_node.m_pNext);
	Push(*other_node.m_pData);
}