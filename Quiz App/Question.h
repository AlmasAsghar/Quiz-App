#ifndef QUESTION_H
#define QUESTION_H
#include "CString.h"
class Question
{
	CString statement;
	CString opt1;
	CString opt2;
	CString opt3;
	int correctOption;
public:
	Question();
	Question(CString stat, CString op1, CString op2, CString op3, int c);
	void AddQuestion(CString stat, CString op1, CString op2, CString op3, int c);
	void AddQuestion(const Question &que);
	Question(const Question&q);
	void displayQuestion();
	//void DisplayCorrectAnswer(int n);
	void setQues(const CString &);
	void setOpt1(const CString &);
	void setOpt2(const CString &);
	void setOpt3(const CString &);
	void setCorrectOpt(const int &);
	CString getQue();
	CString getOpt1();
	CString getOpt2();
	CString getOpt3();
	CString getCorrectOpt();



};
#endif // !QUESTION_H


