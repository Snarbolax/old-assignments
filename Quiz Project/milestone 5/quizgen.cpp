// QuizMaker Milestone 5 (Iteration) Function: this program is designed to allow users to create a quiz with any number of pairs(of a single question and answer) via navigating through a menu.
#include <iostream>
#include <string>
#include "quiz.hpp"

using namespace std;

quiz question_index(50);

int main()
{
	char option_selection;

	cout << "Welcome to QuizMaker" << endl;

	do
	{
		cout << "\nWhat would you like to do?" << endl;

		//call the create_question function to create a question object and store the question into the quiz object
		cout << "a. Create a question" << endl;

		//display all questions inside the quiz object
		cout << "b. Display questions" << endl;

		//save all questions to a file using the given filename
		cout << "c. Save questions" << endl;

		//load the file given as parameter, create question objects and store into the question array
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
			question_index.add_question(create_question());
			break;
		case 'b':
			question_index.display();
			break;
		case 'c':
			cout << "\nWhat filename would you like to use?";
			string filename;
			getline(cin, filename);
			question_index.save(filename);
			break;
		case 'd':
			cout << "\nWhat filename would you like to load?";
			string filename;
			getline(cin, filename);
			question_index.load(filename);
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
