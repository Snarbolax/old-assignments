// QuizMaker Milestone 2 (Iteration) Function: this program is designed to allow users to create a quiz with any number of pairs (of a single question and answer) via navigating through a menu. Up to a maximum of 100 question-answer pairs may be stored in the question_index array.
#include <iostream>
#include <string>
#include "quiz.hpp"

using namespace std;

question question_index[100]; // stores up to a max of 100 question objects

int main()
{
	int count = 0; // used to implement new question objects an array subscripts, in the order of natural numbers
	char option_selection; // will be used to store user inputs to navigate through the main menu

						   // Menu that prompts the user to make a choice between 'a' and 'b'
						   // 'b' leads to ending the loop (i.e. program)
						   // 'a' calls on the addQuestion() function, and and then shows the menu again
						   // Non-applicable inputs invoke "Invalid option", and then shows the menu again

	cout << "Welcome to QuizMaker" << endl;

	do
	{
		cout << "\nWhat would you like to do?" << endl;
		cout << "a. Create a question" << endl;
		cout << "b. Quit" << endl;
		cout << "Choice: ";
		cin >> option_selection;
		cin.ignore(1, '\n');

		//Subsitutes for tolower(option_selection), since it doesn't seem to work.
		if(option_selection == 'B')
			option_selection = 'b';
		else if(option_selection == 'A')
			option_selection = 'a';

		switch (option_selection)
		{
		case 'a':
			question_index[count] = create_question();
			count++;
			break;
		case 'b':
			cout << "\nThank you for using QuizMaker!" << endl;
			break;
		default:
			cout << "\nInvalid option" << endl;
		}
	} while (option_selection != 'b');


	return 0;

}
