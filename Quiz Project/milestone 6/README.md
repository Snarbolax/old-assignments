# QuizMaker Project Milestone 6

This is milestone 6 of the [QuizMaker Project][REDACTED].

# Requirements
The goal of this milestone is to use polymorphism to make it easy to create new
question types and utilize them in quizzes. This milestone requires you to
create a new question type called `tf_question` that represents a true or false
question. The `quiz` class will be modified to allow polymorphism and new
functions are added to handle the creation and loading of `tf_question` objects.

## tf_question class
This class should derive from  `question`

### constructors
- `tf_question()` - sets `_text` to an empty string ("") and `_answer` to "T"

- `tf_question(string text, string answer)` - sets `_text` to the value passed as
a parameter, then checks if the value of the `answer` parameter is "T" or "F". If
it is, then assign it to `_answer`. However, if it is not then it sets
`_answer` to "T" and displays a notification on the screen:
`"Invalid answer. Setting answer to True.\n"`

### member functions
- `virtual void set_answer(string answer)` - overrides the `set_answer` method
of `question` so that its value can only be set to "T" or "F". If an invalid
value is passed, the answer will be set to "T" and it displays a notification on
 the screen: `"Invalid answer. Setting answer to True.\n"`
- `virtual string as_save_text` - overrides the `as_save_text` method of
`question` to indicate that it is a `tf_question` type, the function behaves the
same way, but uses [TFQ] to indicate it is a true or false question and its
answer will only have a value "T" or "F", for example:
```
[TFQ]
C++ is a strongly-typed language
T
```

## question class modifications

### member functions
- `virtual void set_answer(string answer)` - the accessor is now made `virtual`
so that it can be overriden by derived classes, there are no changes to its
behavior
- `virtual string as_save_text()` - the accessor is now made `virtual`
so that it can be overriden by derived classes, there are no changes to its
behavior

## quiz class modifications
### data members
- `_questions` - this should now be a pointer to an array of question pointers,
so its data type should be modified accordingly, all code that access this
variable will need to be updated, this [discussion](https://github.com/ILXL-guides/dynamic_memory_allocation)
can help you identify the appropriate data type to use

### constructors/destructors
  - `quiz(int capacity)` - make sure you update the way `_questions` is
  created
- `~quiz()` - make sure to deallocate each address in the array before
deallocating the array itself,  this [discussion](https://github.com/ILXL-guides/dynamic_memory_allocation)
 can guide you in the process

### member functions
- `add_question(question* q)` - this function will behave the same way, but now
uses a `question` pointer parameter so that it can accept a pointer to a
 `question` or any of its derived classes (using polymorphism)
- `question* get_question(int index)` - this will now return the address of the
object in the array that may point to a `question` object or any of its derived
classes
- `display()` - uses the same behavior but make sure you update how it uses
`_question`

- `save(string filename)` - uses the same behavior but make sure you update how
it uses `_question`, uses the same file format in previous milestones, take note
of how it produces the correct output with minimal changes to the code. See the
example below:
```
2
[SQ]
Who developed Linux?
Linus Torvalds
[TFQ]
C++ is a strongly-typed language
T
```
- `load(string filename)` - make sure you update how it uses `_question`, it
should now check whether the question type is a `question` ([SQ]) or a
`tf_question` ([TFQ]) then creates the corresponding object type and adds it to
`_questions`, the rest of the function's behavior is the same

## global functions
### new function
- `tf_question* create_tf_question()` - asks the user to input the text and
answer to a true or false question then dynamically creates a `tf_question`
object using the user's inputs, the function returns the address of the object,
use the example below for the screen output

```
Please enter your True/False question: C++ is a strongly-typed language
Please enter the answer (T/F): T
True/False question added!
```

*In case the user does not input T or F, it should show the following
notification*
```
Please enter your True/False question: C++ is a strongly-typed language
Please enter the answer (T/F): x
Invalid answer. Setting answer to True.\n
True/False question added!
```

### modification
- `question* create_question()` - uses the same behavior but it should now
dynamically allocate a `question` object and return its address

## menu
- *Create a True/False question* - add a new menu option that will call the
`create_tf_question()` function to create a `tf_question` object

*Make sure the letters for the options in the menu are updated*

### Sample output
```
Welcome to QuizMaker

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: e

What file would you like to load? questions.txt
File loaded successfully!

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: c

Question and Answer list
1. Who is the mother of the COBOL programming language?
Answer: Grace Hopper
2. Who developed C++?
Answer: Bjarne Stroustrup
3. Who developed the Ruby programming language?
Answer: Yukihiro Matsumoto
4. C++ is a strongly-typed language.
Answer: T

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: a

Please enter your question: Who developed Java?
Please enter the answer: James Gosling
Question added!

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: b

Please enter your True/False question: Python is a strongly-typed language
Please enter the answer (T/F): F
True/False question added!

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: c

Question and Answer list
1. Who is the mother of the COBOL programming language?
Answer: Grace Hopper
2. Who developed C++?
Answer: Bjarne Stroustrup
3. Who developed the Ruby programming language?
Answer: Yukihiro Matsumoto
4. C++ is a strongly-typed language.
Answer: T
5. Who developed Java?
Answer: James Gosling
6. Python is a strongly-typed language
Answer: F

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: b

Please enter your True/False question: Javascript is a weakly-typed language
Please enter the answer (T/F): x
Invalid answer. Setting answer to True.
True/False question added!

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: d

What filename would you like to use? questions.txt
File saved successfully!

What would you like to do?
a. Create a question
b. Create a True/False question
c. Display questions
d. Save questions
e. Load questions
f. Quit
Choice: f

Thank you for using QuizMaker!
```

Place the function prototypes and classes in `quiz.hpp`, the function
implementations in `quiz.cpp`, and the main function in `quizgen.cpp`.

# Coding style
We are rolling out a CSUF coding style that we have been using in class. Please
use this new style for this milestone and your following milestones. See [CSUF C++ Style Guide](https://drive.google.com/file/d/1KmXTwiDfpGUN-5GTVZn_xfwJ4yXDMJ4k/view?usp=sharing).

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for
commenting details.

*Take note that we only use th Google document for commenting
style and not coding style.*

## File comments
Describe the contents of the file on the first line. For example:

```cpp
// This file implements a simple calculator
```

## Function comments
Describe the use of the function and how it is implemented if it is non-obvious. For example:

```cpp
// Displays a greeting on the command line using the name parameter.
void show_greeting(string name) {
  // ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the distance formula
// sqrt((x1-x2)^2 + (y1-y2)^2)
double dist = sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
```