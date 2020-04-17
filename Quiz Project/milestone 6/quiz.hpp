#include <string>

using namespace std;

question* create_question();

tf_question* create_tf_question();

// a class used to store question-answer pairs from user inputs
class question
{
private:
	string _text; //question text
	string _answer; //answer to question

public:

	//initializes the question object by setting _text and _answer according to the parameters
	question(string text, string answer)
	{
		_text = text;
		_answer = answer;
	}

	question() : question("", "")
	{
	}

	string text() { return _text; }
	string answer() { return _answer; }

	void set_text(string text) { _text = text; } // will be used to change question-text via user input
	virtual void set_answer(string answer) { _answer = answer; } // will be used to change the question's answers via user input

														 //returns a bool that indicates whether the parameter is the correct answer to the question
	bool check(string answr);

	//converts the question object into a string that is used for saving it to a file, the function returns this string and follows the format below
	virtual string as_save_text();

};


class quiz : public question
{
private:
	question** _questions; //pointer to an array of questions in the heap
	int _size; //the number of question objects in the array
	int _capacity; //total number of question objects the array can hold
public:
	quiz(int capacity)
	{
		_size = 0;
		_capacity = capacity;
		_questions = new question*[capacity];
	}

	quiz() : quiz(100)
	{
	}

	//deallocate the memory occupied by the array that _questions points to
	~quiz()
	{
		for (int i = 0; i < _capacity; i++)
		{
			delete *(_questions + i);
			*(_questions + i) = NULL;
		}
		delete[] _questions;
		_questions = nullptr;
	}

	int size()
	{
		return _size;
	}

	int capacity()
	{
		return _capacity;
	}

	void add_question(question q);

	//returns the question object in the specified index
	question* get_question(int index)
	{
		return (*(_questions + index));
	}

	void display();

	void save(string filename);

	void load(string filename);
};

class tf_question : public question {
	public:
		tf_question() : question("", "T")
		{
		}

		tf_question(string text, string answer)
		{
			set_text(text);
			if (answer == "T" || answer == "F")
			{
				set_answer(answer);
			}
			else
			{
				set_answer("T");
				cout << "Invalid answer. Setting answer to True.\n";
			}
		}

		virtual void set_answer(string answer);

		virtual string as_save_text();
};