#ifndef QUIZ_H
#define QUIZ_H
#include "Question.h"
class Quiz
{
	Question **q;
	int capacity;
	int noOfQuestions;
public:
	Quiz();
	Quiz(int);
	Quiz(const Quiz &que);
	void displayQuize();
	void addQuizQuestion(Question &q);
	~Quiz();
};
#endif // !QUIZ_H


