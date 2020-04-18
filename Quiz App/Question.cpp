#include <iostream>
#include "Question.h"
using namespace std;
Question::Question(CString stat, CString op1, CString op2, CString op3, int c) :statement(stat), opt1(op1), opt2(op2), opt3(op3)
{
	correctOption = c;
}
Question::Question()
{
}
void Question::AddQuestion(CString stat, CString op1, CString op2, CString op3, int c)
{
	statement = stat;
	opt1 = op1;
	opt2 = op2;
	opt3 = op3;
	correctOption = c;
}
void Question::displayQuestion()
{
	cout << "  ";
	statement.display();
	cout << "\n(1)        :";
	opt1.display();
	cout << "\n(2)        :";
	opt2.display();
	cout << "\n(3)        :";
	opt3.display();
	cout << "\n:";
}
void Question::setQues(const CString &que)
{
	statement = que;
}
void Question::setOpt1(const CString &opt)
{
	opt1 = opt;
}
void Question::setOpt2(const CString &opt)
{
	opt2 = opt;
}
void Question::setOpt3(const CString &opt)
{
	opt3 = opt;
}
void Question::setCorrectOpt(const int &correct)
{
	correctOption = correct;
}
CString Question::getQue()
{
	return statement;
}
CString Question::getOpt1()
{
	return opt1;
}
CString Question::getOpt2()
{
	return opt2;
}
CString Question::getOpt3()
{
	return opt3;
}
CString Question::getCorrectOpt()
{
	if (correctOption == 1)
		return opt1;
	else if (correctOption == 2)
		return opt2;
	return opt3;
}

Question::Question(const Question&q)
{
	*this = q;
}
