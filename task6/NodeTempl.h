template <typename T>
class Node {
	Node<T>* m_pNext;
	T* m_pData;
public:
	Node();
	~Node();
	Node(Node<T>*, const T&); 
	template<typename T> friend class MyStack_2;
};

template <typename T> Node<T>::Node() 
{
	m_pNext = nullptr;
	m_pData = nullptr;
}

template <typename T> Node<T>::~Node() 
{
	delete m_pData;
	m_pNext = nullptr;
}

template <typename T> Node<T>::Node(Node<T>* next_node, const T& other_data) 
{
	m_pData = new T(other_data);
	m_pNext = next_node;
}