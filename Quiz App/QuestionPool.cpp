#include <iostream>
using namespace std;
#include "QuestionPool.h"
QuestionPool::QuestionPool()
{
	ptr = nullptr;
	capacity = 0;;
	noOfQuestions = 0;
}

QuestionPool::QuestionPool(int cap)
{
	if (cap <= 0)
		cap = 10;
	capacity = cap;
	noOfQuestions = 0;
	ptr = new Question*[capacity];
	for (int i = 0; i < capacity; i++)
		ptr[i] = nullptr;
}
void QuestionPool::DispalyQuestion(int questionNumber)
{
	if (questionNumber - 1 >= noOfQuestions)
		exit(0);
	ptr[questionNumber - 1]->displayQuestion();

}

void QuestionPool::AddQuest(CString stat, CString op1, CString op2, CString op3, int c)
{
	if (noOfQuestions >= capacity)
		exit(0);
	ptr[noOfQuestions] = new Question;
	ptr[noOfQuestions]->AddQuestion(stat, op1, op2, op3, c);
	noOfQuestions++;
}
void QuestionPool::generateQuiz(int num, Quiz& que)
{
	if (num > noOfQuestions)
		exit(0);
	srand(time(0));
	int n, count = 0;
	while (count < num)
	{
		n = (1 + rand() % (noOfQuestions)) - 1;
		que.addQuizQuestion(*ptr[n]);
		count++;
	}
}
QuestionPool::~QuestionPool()
{
	if (ptr)
	{
		for (int i = 0; i < noOfQuestions; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	ptr = nullptr;
	noOfQuestions = 0;
	capacity = 0;
}
void QuestionPool::deleteQuestion(int n)
{
	if (n >= noOfQuestions)
		exit(0);
	delete ptr[n];
	if (n < noOfQuestions)
	{
		ptr[n] = ptr[noOfQuestions];
		ptr[noOfQuestions] = nullptr;
	}
	noOfQuestions--;
	
}