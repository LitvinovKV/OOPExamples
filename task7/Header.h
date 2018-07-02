#include<vector>
using namespace std;

template <typename T> void AllAboutVector(vector<T>& my_vector) //Информация о векторе
{
	cout << '\n';
	cout << "Size of vector = " << my_vector.size() << endl;
	cout << "Capacity of vector = " << my_vector.capacity() << endl;
	cout << "Max_size of vector = " << my_vector.max_size() << endl;
}

template <typename T> void DeleteSequence(vector<T>& my_vector) //Удалитть последовательность
{
	vector<T>::iterator it = my_vector.begin();
	while (it != my_vector.end())
	{
		bool flag = false;
		vector<T>::iterator jt = it + 1; //новый итератор, для подцикла
		while (jt != my_vector.end())
		{
			if (*it == *jt)
			{
				jt = my_vector.erase(jt);
				flag = true;
			}
			else
				jt++;
		}
		if (flag == true)
			it = my_vector.erase(it);
		it++;
	}
}

template <typename T> vector<T> InvertVector(vector<T>& my_vector) //Значения вектора в обратном порядке
{
	//vector<T>::iterator it;
	vector<T> new_vector;
	for (int i =  my_vector.size() - 1; i >= 0; i--)
		new_vector.push_back(my_vector[i]);
	return new_vector;
}

template <typename T> void coutContainer(T& my_container)
{
	T::iterator it;
	cout << "Type: " << typeid(*my_container.begin()).name() << endl;
	//for (it = my_container.begin(); it < my_container.size(); it++)
	for (it = my_container.begin(); it != my_container.end(); it++)
	{
		cout << *it << ' ';
		cout << endl;
	}
}

