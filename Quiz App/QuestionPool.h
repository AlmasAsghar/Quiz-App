#ifndef QUESTION_POOL_H
#define QUESTION_POOL_H
#include "Question.h"
#include "Quiz.h"
#include<ctime>
class QuestionPool
{
	Question **ptr;
	int noOfQuestions;
	int capacity;
public:
	QuestionPool();
	QuestionPool(int capacity);
	void DispalyQuestion(int questionNumber);
	void generateQuiz(int q, Quiz& que);
	void AddQuest(CString stat, CString op1, CString op2, CString op3, int c);
	~QuestionPool();
	void deleteQuestion(int n);

};
#endif // !QUESTION_POOL
