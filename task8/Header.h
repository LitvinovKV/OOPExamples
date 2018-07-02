template <typename T> void CoutAdapter(T stack_pq) //Вывод элементов для stack и priority_queue
{
	while (!stack_pq.empty())
	{
		cout << stack_pq.top() << ' ';
		stack_pq.pop();
	}
	cout << endl;
}


template <typename T> void CoutReverseStack(T my_stack)
{
	T local_adapter;
	while (!my_stack.empty())
	{
		local_adapter.push(my_stack.top());
		my_stack.pop();
	}
	my_stack.swap(local_adapter);
	while (!my_stack.empty())
	{
		cout << my_stack.top() << ' ';
		my_stack.pop();
	}
	cout << endl;
}

template <typename T> void coutContainer(T& my_container)
{
	T::iterator it;
	int i = 0;
	for (it = my_container.begin(); i < my_container.size(); it++)
	{
		cout << *it << ' ';
		i++;
	}
	cout << endl;
}