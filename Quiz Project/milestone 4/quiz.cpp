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
	cout << "Question and Answer list" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". " << array[i].text() << endl;
		cout << "Answer: " << array[i].answer() << endl;
	}

	cout << endl;

}


// saves the current array of questions into a file.
void save_questions(question array[], int size, string filename)
{
	ofstream outputfile;
	outputfile.open(filename);

	outputfile << size << endl;

	for (int i = 0; i < size; i++)
	{
		outputfile << "[SQ]\n" << array[i].text() << "\n";
		outputfile << array[i].answer() << "\n";
	}
	outputfile.close();
	cout << "File saved successfully!\n\n";
}

// loads questions and answers from a file onto an array. Replaces the value of the size variable from quizgen.cpp with the first line of the file. Question texts and answers in the indexes after the changed size variable are emptied.
void load_questions(question array[], int size, string filename)
{
	ifstream inputfile;
	inputfile.open(filename);
	int* size_loc = &size;

	inputfile >> *size_loc;

  for (int i = 0; i < *size_loc; i++)
	{
		inputfile >> (*(array + i)).set_text();
		inputfile >> (*(array+i)).set_answer();
	}

  for (int j = *size_loc; j < 100; j++)
  {
		(*(array + j)).set_text("");
		(*(array + j)).set_answer("");
  }

	inputfile.close();
	cout << "File loaded successfully!\n" << endl;
}
