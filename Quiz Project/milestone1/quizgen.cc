// QuizMaker Milestone 1 (Iteration) Function: this program is designed to allow users to create a quiz with any number of pairs (of a single question and answer) via navigating through a menu. For the Milestone 1 Iteration of the program, answers and questions are not properly stored for usage in future program executions. This is intended.

#include <iostream>
#include <string>

using namespace std;


/* Prompts the user to enter a question and an answer for the question.
   Uses the getline() functions in order to allow inputs to include whitespace.
   Might interacting with global arrays to store the questions and answers in future milestones.*/
void addQuestion ()
{
  string question;
  string answer;

  cout << "\nPlease enter your question: ";
  getline(cin, question);
  cout << "Please enter the answer: ";
  getline(cin, answer);
  cout << "Question added!" << endl;
}

int main()
{

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
    cin.get(option_selection);
    cin.ignore(1, '\n'); // removes the \n created by user pressing the "enter" key, from the input buffer
	tolower(option_selection); // changes uppercase inputs to lowercase, for user convenience.

    switch (option_selection)
      {
		case 'a':
			addQuestion();
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
