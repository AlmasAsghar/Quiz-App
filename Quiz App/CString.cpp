#include <iostream>
using namespace std;
#include "CString.h"
CString::CString()
{
	data = nullptr;
	//cout << "CString()" << endl;
	size = 0;
}
CString::CString(char c)
{
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
	//cout << "CString( char c)" << endl;
}
CString::CString(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	size = i + 1;
	data = new char[size];
	strCpy(data, s);
	//cout << "CString( char *c)" << endl;
}

CString::~CString()
{
	if (data)
		delete[] data;
	data = nullptr;
	size = 0;
	//cout << "~CString()" << endl;
}
CString::operator int()
{
	int i = 0;
	int x = data[0];
	return x;
}
void CString::trimLeft()
{
	int i = 0;
	while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
	{
		remove(i, 1);
	}
}
void CString::trim()
{
	trimRight();
	trimLeft();
}

int CString::compare(CString s2)const
{
	int i = 0;
	if (getlength() < s2.getlength())
		return -1;
	else if (getlength() > s2.getlength())
		return 1;
	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		if (data[i] > s2.data[i])
			return 1;
		else if (data[i] < s2.data[i])
			return -1;
		i++;
	}
	return 0;
}
void CString::reverse()
{
	int i = 0, j = 0;
	char temp;
	int index = getlength();
	while (i <(getlength() / 2))
	{
		temp = data[i];
		data[i] = data[index - (i + 2)];
		data[index - (i + 2)] = temp;
		i++;
	}
}
void CString::makeUpper()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'a'&&data[i] <= 'z')
			data[i] = data[i] - 32;
		i++;
	}
}
void CString::makeLower()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A'&&data[i] <= 'Z')
			data[i] = data[i] + 32;
		i++;
	}
}
void CString::trimRight()
{
	int i = size - 2;
	while (data[i] == ' ' || data[i] == '\n' || data[i] == '\t')
	{
		remove(i, 1);
		i--;
	}
}
void CString::input()
{
	this->~CString();
	data = new char[1];
	data[0] = '\0';
	size = 1;
	char ch;
	int i = 0;
	while ((ch = cin.get()) != '\n')
	{
		at(i) = ch;
		if (i + 1 == size)
			reSize(size * 2);
		i++;
	}
	data[i] = '\0';
	/*char p=' ';
	int i = 0;

	while (p != '\n')
	{
	cin.get(p);

	if (i == 0 || i < size - 1)
	reSize(i+20);
	at(i) = p;
	i++;
	at(i) = '\0';
	}*/

}
const char &  CString::operator [](const int index)const
{
	if (index<0 && index>size - 1)
		exit(0);
	char &p = data[index];
	return p;
}
char &  CString::operator [](const int index)
{
	if (index<0 && index>size - 1)
		exit(0);
	char &p = data[index];
	return p;
}
char & CString::at(int index)
{
	if (index<0 && index>size - 1)
		exit(0);
	char &p = data[index];
	return p;
}
void CString::reSize(int r)
{
	/*char *p = new char[r];
	for (int i = 0; i < getlength() && i < r; i++)
	{
	p[i] = this->data[i];
	}
	this->~CString();
	this->data = p;
	this->size = r;*/

	char *ptr = new char[r];
	int i = 0;
	if (data)
	{
		while (data[i] != '\0'&&i<r - 1)
		{
			ptr[i] = data[i];
			i++;
		}
	}
	ptr[i] = '\0';
	this->~CString();
	size = r;
	data = new char[size];
	strCpy(data, ptr);
	delete[] ptr;
	ptr = nullptr;
}
bool CString::isEmpty() const
{
	if (!data)
		return true;
	return false;
}
int CString::getlength() const
{
	int i = 0;
	if (!data)
		return 1;
	while (data[i] != '\0')
		i++;
	return i + 1;
}
void CString::display() const
{
	if (size > 0)
		cout << data;
}
int CString::find(CString subStr, int start)const
{
	int count = 0;
	if (start<0 || start>subStr.getlength())
		return 0;
	int length = subStr.getlength();
	while (data[start] != '\0')
	{
		int i = 0;
		if (subStr.data[i] == data[start])
		{
			while (subStr.data[i] == data[start] && data[start] != '\0'&&subStr.data[i] != '\0')
			{
				i++; start++;
			}
		}
		if (i == length - 1)
			return start - (length - 1);
		else
			start++;
	}
	return -1;
}
void CString::insert(int index, CString subStr)
{
	int newSize = getlength() + subStr.getlength();
	char *ptr = new char[newSize];
	int k = 0, i = 0;
	while (k<newSize&&data[i] != '\0')
	{
		if (i == index)
		{
			int j = 0;
			while (subStr.data[j] != '\0')
			{
				ptr[k] = subStr.data[j];
				j++; k++;
			}
		}
		ptr[k] = data[i];
		i++; k++;
	}
	ptr[k] = '\0';
	size = newSize;
	delete[] data;
	data = nullptr;
	data = new char[size];
	strCpy(data, ptr);
	delete[] ptr;
	ptr = nullptr;
}
void CString::strCpy(char *str, char *ptr) const
{
	int i = 0;
	while (ptr[i] != '\0')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
}
void CString::remove(int index, int count)
{
	int i = 0, j = 0;
	char *ptr = new char[size];
	while (data[i] != '\0')
	{
		if (i == index)
		{
			i = i + count;
			if (i >= size - 1)
				break;
		}
		ptr[j] = data[i];
		j++; i++;
	}
	ptr[j] = '\0';
	strCpy(data, ptr);
	delete[] ptr;
	ptr = nullptr;
}
int  CString::replace(CString old, CString newSubStr)
{
	int sizeDiffer = 0, newSize = 0, count = 0;
	int i = 0, j = 0;
	while (data[i] != '\0')
	{
		if (findSubString(data, old, i))
		{
			remove(i, old.size - 1);
			insert(i, newSubStr);
			count++;
		}
		i++;
	}
	return count;
}
bool CString::findSubString(char *str, CString subStr, int start)
{
	int i = 0;
	if (str[start] == subStr.data[i])
	{
		while (subStr.data[i] != '\0' &&str[start] != '\0'&& str[start] == subStr.data[i])
		{
			start++; i++;
		}
		if (i == subStr.size - 1)
			return true;
	}
	return false;

}
CString CString::left(int count)
{
	char temp = data[count];
	data[count] = '\0';
	CString s = new char[count + 1];
	strCpy(s.data, data);
	data[count] = temp;
	size = count + 1;
	return s;
}
CString CString::concat(CString s2) const
{
	/*CString copy;
	copy.size = getlength() + s2.getlength();
	copy.data = new char[copy.size];
	strCpy(copy.data, data);
	int i = getlength() - 1;
	int j = 0;
	while (s2.data[j] != '\0')
	{
	copy.data[i] = s2.data[j];
	i++;
	j++;
	}
	copy.data[i] = '\0';
	return copy;*/
	CString s;
	s.size = getlength() + s2.getlength();
	s.data = new char[s.size];
	strCpy(s.data, data);
	int i = getlength() - 1, j = 0;
	while (s2.data[j] != '\0')
	{
		s.data[i] = s2.data[j];
		j++; i++;
	}
	s.data[i] = '\0';
	return s;
}
CString CString::operator + (const CString &s2) const
{
	CString s;
	s.size = getlength() + s2.getlength();
	s.data = new char[s.size];
	strCpy(s.data, data);
	int i = getlength() - 1, j = 0;
	while (s2.data[j] != '\0')
	{
		s.data[i] = s2.data[j];
		j++; i++;
	}
	CString a;
	s.data[i] = '\0';
	return s;
}
CString CString::right(int count)
{
	CString s;
	s.size = count + 1;
	s.data = new char[s.size];
	int i = getlength() - count - 1;

	int j = 0;
	while (data[i] != '\0')
	{
		s.data[j] = data[i];
		i++; j++;
	}
	s.data[j] = '\0';
	return s;
}
int CString::toInteger()const
{
	int i = 0, j = 1, number = 0, asci = 0;

	while (data[i] != '\0'&&data[i] != '.')
	{
		if (data[i] < '0'&&data[i] > '9')
			return 0;
		asci = data[i] - '0';
		number = number * 10 + asci;
		i++;
	}
	return number;
}
//void CString::resize(int r)
//{
//	char *ptr = new char[r];
//	int i = 0;
//	while (data[i] != '\0')
//	{
//		ptr[i] = data[i];
//		i++;
//	}
//	ptr[i] = '\0';
//	delete[] data;
//	data = nullptr;
//	size = r;
//	data = new char[size];
//	strCpy(data, ptr);
//	delete[] ptr;
//	ptr = nullptr;
//}
CString::CString(const CString &s)
{
	if (s.data == nullptr)
	{
		size = 0;
		data = nullptr;
		//cout << "copy" << endl;
		return;

	}
	//cout << "copy" << endl;
	size = s.size;
	data = new char[size];
	strCpy(data, s.data);
}
CString & CString::operator = (const CString & s)
{
	if (this == &s)
		return *this;
	if (s.data == nullptr)
	{
		size = 0;
		data = nullptr;
		//return *thi;
	}
	//cout << "copy" << endl;
	size = s.size;
	data = new char[size];
	strCpy(data, s.data);
	return *this;
}
float CString::toFloat() const
{
	int i = 0, j = 1;
	float n = 0;
	int num = toInteger();
	while (data[i] != '.'&&data[i] != '\0')
		i++;
	while (data[i] != '\0')
	{
		i++;
		n = n * 10 + (data[i] - '0');
		j = j * 10;
	}
	n = n / j;
	return n + num;
}
void CString::operator +=(CString c2)
{
	int i = getlength() - 1;
	reSize(getlength() + c2.getlength());
	int j = 0;
	while (c2.data[j] != '\0')
	{
		data[i] = c2.data[j];
		i++; j++;
	}
	data[i] = '\0';
}
void CString::concatEqual(CString c2)
{
	int i = getlength() - 1;
	reSize(getlength() + c2.getlength());
	int j = 0;
	while (c2.data[j] != '\0')
	{
		data[i] = c2.data[j];
		i++; j++;
	}
	data[i] = '\0';
}
CString CString::tokenize(CString delim)
{
	int i = 0;
	bool flag = true;
	CString s;
	s.data = new char[size];
	s.size = size;
	while (data[i] != '\0'&&flag)
	{
		int j = 0;
		while (delim.data[j] != '\0')
		{
			if (data[i] == delim.data[j])
			{
				flag = false;
				break;
			}
			j++;
		}
		if (flag)
		{
			s.data[i] = data[i];
			i++;
		}
	}
	remove(0, i + 1);
	s.data[i] = '\0';
	return s;
}
CString CString::operator () (CString delim)
{
	int i = 0;
	bool flag = true;
	CString s;
	s.data = new char[size];
	s.size = size;
	while (data[i] != '\0'&&flag)
	{
		int j = 0;
		while (delim.data[j] != '\0')
		{
			if (data[i] == delim.data[j])
			{
				flag = false;
				break;
			}
			j++;
		}
		if (flag)
		{
			s.data[i] = data[i];
			i++;
		}
	}
	remove(0, i + 1);
	s.data[i] = '\0';
	return s;
}
//istream & CString::operator >> (istream &i, CString &p)
//{
//	char p = ' ';
//	cout << " enter the character string \n";
//	int i = 0;
//	while (p != '\n')
//	{
//		i.get(p);
//		if (i == 0 || i < size - 1)
//			reSize(i + 20);
//		at(i) = p;
//		i++;
//	}
//	at(i) = '\0';
//}