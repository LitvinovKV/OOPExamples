#include "MyString.h"



int main()
{
	{
		MyString s7("aaa");
		MyString s3("zxy");
		MyString s1("abc");
		MyString s4("kkk");

		MyString s2("abc");

		MyString s5(s4);
		MyString s6(move(s2));
		s5 = s3;
		//s6 = move(s1);

		MyString::PrintAll();

		MyString::Sorting(); // WAS PROBLEM!
		cout << '\n';
		MyString::PrintAll();

		MyString::EditRegister();
		cout << '\n';
		MyString::PrintAll();
	}
	cout << '\n';
	MyString::PrintAll();
	system("pause");
	return 0;
}