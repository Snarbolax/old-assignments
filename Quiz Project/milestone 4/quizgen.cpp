// QuizMaker Milestone 4 (Iteration) Function: this program is designed to allow users to create a quiz with any number of pairs(of a single question and answer) via navigating through a menu. Up to a maximum of 100 question-answer pairs may be stored in the question_index array.
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

	int size = 0;
	string filename;

	cout << "Welcome to QuizMaker" << endl;

	do
	{
		size = (sizeof(question_index) / sizeof(question));
		cout << "\nWhat would you like to do?" << endl;
		cout << "a. Create a question" << endl;
		cout << "b. Display questions" << endl;
		cout << "c. Save questions" << endl;
		cout << "d. Quit" << endl;
		cout << "Choice: ";
		cin >> option_selection;
		cin.ignore(1, '\n');

		//Subsitutes for tolower(option_selection), since it doesn't seem to work.
		if(option_selection == 'B')
			option_selection = 'b';
		else if(option_selection == 'A')
			option_selection = 'a';
		else if(option_selection == 'C')
  			option_selection = 'c';
		else if(option_selection == 'D')
    		option_selection = 'd';
    else if(option_selection == 'E')
      	option_selection = 'e';

		switch (option_selection)
		{
		case 'a':
			question_index[count] = create_question();
			count++;
			break;
		case 'b':
			display_questions(question_index, size);
			break;
		case 'c':
			cout << "\nWhat filename would you like to use?";
			getline(cin, filename);
			save_questions(question_index, size, filename);
			break;
		case 'd':
      cout << "\nWhat filename would you like to load?";
      getline(cin, filename);
      load_questions(question_index, size, filename);
      break;
    case 'e':
  		cout << "\nThank you for using QuizMaker!" << endl;
  		break;
		default:
			cout << "\nInvalid option" << endl;
		}
	} while (option_selection != 'd');


	return 0;

}
