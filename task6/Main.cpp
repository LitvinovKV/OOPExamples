#include <tchar.h>
#include <iostream>
#define stop __asm nop

#include "templ.h"
#include "MyString.h"
#include "MyStackTempl.h"
#include "CircleBuffer.h"

template <> void Swap<MyString>(MyString& a, MyString& b)
{
	char* temp = a.m_pStr;
	a.m_pStr = b.m_pStr;
	b.m_pStr = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	
	
	try
	{
		MyStack <int, 5> iStack;
		iStack.Push(4);
		iStack.Push(8);
		iStack.Push(15);
		iStack.Pop();

		MyStack <MyString, 10> strStack;
		strStack.Push("AAA");
		strStack.Push("qwert");
		strStack.Push("ABC");
		strStack.Pop();
	}
	catch (const out_of_range& e)
	{
		cout << e.what() << endl;
	}
	
	{
		MyStack_2<int> My_st;
		My_st.Push(2);
		My_st.Push(10);
		My_st.Push(3);
		My_st.Push(50);
		My_st.Push(88);
		My_st.CoutMyStack_2();
		cout << endl;
		
		MyStack_2 <int> NewStack;
		NewStack.Push(100);
		NewStack.Push(300);
		NewStack.CoutMyStack_2();
		cout << endl;
		My_st = NewStack;
		My_st.CoutMyStack_2();

	}
	
	{
		try
		{
			CircleBuffer <int, 5> MyBuf;

			MyBuf.Push(7);
			MyBuf.Push(8);
			MyBuf.Push(12);
			MyBuf.Push(4);
			MyBuf.Push(67);
			
			MyBuf.Pop();
			MyBuf.Pop();

			MyBuf.ResizeBuffer(7);

			CircleBuffer <int, 5> My222buffer(MyBuf);
			CircleBuffer <int, 5> My100buffer(std::move(MyBuf));
			
			My100buffer.Push(50);
			My222buffer = std::move(My100buffer);
			cout << My222buffer << endl;
		}
		catch (const out_of_range& e)
		{
			cout << e.what() << endl;
		}
	}
	
	system("pause");
	return 0;
}