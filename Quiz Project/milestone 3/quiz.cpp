#include <iostream>
#include <fstream>
#include <string>
#include "quiz.hpp"

using namespace std;
/* Prompts the user to enter a question and an answer for the question.
Uses the getline() functions in order to allow inputs to include whitespace.
Utilizes the question class, which its implementation may be found in quiz.hpp */
question create_question()
{
	question question_pair;
	string text;
	string answer;

	cout << "\nPlease enter your question: ";
	getline(cin, text);
	question_pair.set_text(text);
	cout << "Please enter the answer: ";
	getline(cin, answer);
	question_pair.set_answer(answer);
	cout << "Question added!" << endl;

	return question_pair;
}

void display_questions(question array[], int size)
{
	cout << "\nQuestion and Answer list" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". " << array[i].text() << endl;
		cout << "Answer: " << array[i].answer() << endl;
	}

}

void save_questions(question array[], int size, string filename)
{
	ofstream outputfile;
	outputfile.open(filename);

	outputfile << size << endl;

	for (int i = 0; i < size; i++)
	{
		outputfile << "[SQ]\n" << array[i].text() << endl;
		outputfile << array[i].answer() << endl;
	}
	outputfile.close();
}
