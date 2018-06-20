class MyString
{
	char* m_pStr;
public:
	MyString();
	MyString(char*);
	~MyString();
	MyString& operator= (const MyString&);
	MyString(const MyString& other); 
	char* operator*();
	template <typename T> friend void Swap (T&, T&);
};
