#include <string>

using namespace std;
// a class used to store question-answer pairs from user inputs
class question
{
	private:
		string _text;
		string _answer;

	public:
		string text() { return _text; }
		string answer() { return _answer; }

		void set_text(string text) { _text = text; } // will be used to change question-text via user input
		void set_answer(string answer) { _answer = answer; } // will be used to change the question's answers via user input

};


question create_question();
void display_questions(question array[], int size);
void save_questions(question array[], int size, string filename);
