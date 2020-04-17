# QuizMaker Project Milestone 2

This is milestone 2 of the [QuizMaker Project][REDACTED].

# Requirements
Design the `question` class that contains two data members: `_text` and `_answer`. Provide the appropriate accessor and mutator methods that will be used to access the data members. Use appropriate access specifiers so that the data members are only accessible through the accessor and mutators.

Implement the `create_question` function that does not receive any parameters, but returns a `question` object. The function should ask the user to input the question and answer then store this information into a `question` object. This object should be returned by the function. You can reuse your code from the `addQuestion` function from milestone 1.

Develop a menu-based command-line interface (CLI) that repeatedly asks a user to input a question and answer until the option to exit is used. Call the `create_question` function to ask for user's input. Kindly refer to the sample runs below and follow the output as closely as possible.

```
Welcome to QuizMaker

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: Who is the mother of the COBOL programming language?
Please enter the answer: Grace Hopper
Question added!

What would you like to do?
a. Create a question
b. Quit
Choice: x

Invalid option

What would you like to do?
a. Create a question
b. Quit
Choice: b

Thank you for using QuizMaker!
```

In this version, you should create an array of 100 `question` objects in the driver (`main.cpp`). Every time `create_question` is called, the object returned should be added to the end of the array such that the first object is in index 0, the second will be in index 1, and so forth.

Place the function prototypes and classes in `quiz.hpp`, the function implementations in `quiz.cpp`, and the main function in `quizgen.cpp`.

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for more details.

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