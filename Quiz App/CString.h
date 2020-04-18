#ifndef C_STRING
#define C_STRING
class CString
{
private:
	char *data;
	int size;
	bool findSubString(char *Str, CString subStr, int start);
	void strCpy(char *str, char *ptr)const;
public:
	CString();
	CString(char c);
	CString(char *);
	CString(const CString &);
	CString & operator = (const CString & ref);
	~CString();
	void input();
	char & at(int index);
	char & operator [](const int index);
	const char & operator [](const int index) const;
	//void shrink();
	bool isEmpty() const;
	int getlength() const;
	void display()const;
	int find(CString subStr, int start = 0) const;
	void insert(int index, CString subStr);
	void remove(int index, int count = 1);
	int replace(CString old, CString newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	int compare(CString s2) const;
	CString right(int);
	CString left(int);
	int toInteger() const;
	CString concat(CString s2) const;
	CString operator + (const CString &s2) const;
	float toFloat() const;
	void concatEqual(CString c2);
	void operator +=(CString s2);
	CString tokenize(CString delim);
	CString operator () (CString delim);
	operator int();
	/*void operator =(CString s)
	{
	date = 15;
	month = 2;
	year = 2016;
	}*/
	/*operator Date()
	{
	Date d;
	return d;
	}*/
	//CString::operator Date()
	//{
	//	Date d;
	//	d.setDay = 15;
	//	d.setMonth = 5;
	//	d.setYear = 2015;
	//	return d;
	//}


};
//istream &operator >> (istream &is, CString &r);
//ostream &operator<<(ostream &s, CString &r);

#endif // !C_STRING

#pragma once
