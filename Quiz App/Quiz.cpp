#include <iostream>
using namespace std;
#include "Quiz.h"
Quiz::Quiz()
{
	capacity = 0;
	noOfQuestions = 0;
	q = nullptr;
}
Quiz::Quiz(const Quiz &que)
{
	capacity = que.capacity;
	noOfQuestions = que.noOfQuestions;
	q = new Question*[capacity];
	for (int i = 0; i < capacity; i++)
		q[i] = new Question;
	for (int i = 0; i < noOfQuestions; i++)
		q[i] = que.q[i];
}
void Quiz::displayQuize()
{
	for (int i = 0; i < capacity; i++)
	{
		q[i]->displayQuestion();
	}
}
Quiz::Quiz(int x)
{
	if (x <= 0)
		exit(0);
	capacity = x;
	noOfQuestions = 0;
	q = new Question*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		q[i] = nullptr;
	}
}
void Quiz::addQuizQuestion(Question &que)
{
	if (noOfQuestions >= capacity)
		exit(0);
	q[noOfQuestions] = new Question;
	q[noOfQuestions] = &que;
	//q[noOfQuestions] = new Question(que);
	//*q[noOfQuestions]->AddQuestion(que);
	noOfQuestions++;
}









Quiz::~Quiz()
{
	if (q)
	{
		delete[]q;
	}
	q = nullptr;
	noOfQuestions = 0;
}