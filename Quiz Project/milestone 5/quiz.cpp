#include <iostream>
#include <fstream>
#include <string>
#include "quiz.hpp"

using namespace std;
//asks the user to input the text and answer for a question then creates and returns a corresponding question object
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

//adds question objects to the array until capacity is reached, updates _size accordingly, if capacity is reached display the error message: Sorry, can't create any more questions.\n
void quiz::add_question(question q)
{
	if (_size < _capacity)
	{
		*(_questions + _size) = q;
		_size++;
	}
	else
		cout << "Sorry, can't create anyore questions.\n";
}

//displays all question objects in the array using the following format (see the expected output for more details)
void quiz::display()
{
	cout << "Question and Answer list" << endl;
	for (int i = 0; i < _size; i++)
	{
		cout << i + 1 << ". " << (*(_question + i)).text() << endl;
		cout << "Answer: " << (*(_question + i)).answer() << endl;
	}

	cout << endl;
}

//saves all question objects to a file whose name is given as a parameter
void quiz::save(string filename)
{
	ofstream outputfile;
	outputfile.open(filename);

	outputfile << _size << endl;

	for (int j = 0; j < _size; j++)
	{
		outputfile << (*(_question + j)).as_save_text();
	}
	outputfile.close();
	cout << "File saved successfully!\n\n";
}

//loads a file using the parameter and creates the corresponding question objects
void quiz::load(string filename)
{
	ifstream inputfile;
	inputfile.open(filename);

	inputfile >> _size;
	inputfile.ignore();

	string temp;

	~quiz();
	quiz(_size+30);

  for (int k = 0; k < _size; k++)
	{
		getline(inputfile, temp);
		getline(inputfile, temp);
		inputfile >> (*(_question + k)).set_text(temp);
		getline(inputfile, temp);
		inputfile >> (*(_question + k)).set_answer(temp);
	}

	inputfile.close();
	cout << "File loaded successfully!\n" << endl;
}

//returns a bool that indicates whether the parameter is the correct answer to the question
bool question::check(string answr)
{
  if(answr == _answer)
    return true;
  else
    return false;
}

//returns a bool that indicates whether the parameter is the correct answer to the question
string question::as_save_text()
{
  string conversion = "[SQ\n]";
  conversion +=_text;
  conversion +="\n";
  conversion +=_answer;
  conversion +="\n";
  return conversion;
}
