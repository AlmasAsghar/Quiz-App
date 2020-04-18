#include<iostream>
using namespace std;
#include "QuizGenerator.h"
#include"QuestionPool.h"
/*QuizGenerator::QuizGenerator()
{
}
QuizGenerator::QuizGenerator(int x) :qP(x)
{
}*/
void QuizGenerator::start()
{
	QuestionPool qP;
	CString s, s1, s2, s3, s4;
	int n;
	
 do
	{
		cout << "         MENUE         \n";
		cout << "Enter the related number for doing task \n";
		cout << "1= :to add question\n";
		cout << "2= :to generate quiz\n";
		cout << "3= :to get	Question\n";
		cin >> n;
		if (n == 1)
		{
			cin.ignore();
			cout << "enter statment of the question \n";
			s.input();
			cout << "enter the first option\n";
			s1.input();
			cout << "enter the second option \n";
			s2.input();
			cout << "enter the third optioon \n";
			s3.input();
			int option;
			cout << "enter correct option \n";
			cin >> option;
			qP.AddQuest(s, s1, s2, s3, option);
		}
		if (n == 2)
		{
			int num;
			cout << "enter the number of question for quiz \n";
			cin >> num;
			Quiz que(num);
			qP.generateQuiz(num, que);
			que.displayQuize();
		}
		if (n == 3)
		{
			int num;
			cout << "enter question number to dispaly\n";
			cin >> num;
			qP.DispalyQuestion(num);
		}
		if (n == 4)
		{
			int num;
			cout << "enter the question number to delete \n";
			qP.deleteQuestion(1);
		}
//		cin >> n;
	}while (n != 0);
}