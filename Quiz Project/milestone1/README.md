# QuizMaker Project Milestone 1
*Due: September 21, 11:59pm*

This is milestone 1 of the [QuizMaker Project][REDACTED].

# Requirements
Develop a menu-based command-line interface (CLI) that repeatedly asks a user to input a question and answer until the option to exit is used. Kindly refer to the sample runs below and follow the output as closely as possible.

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

Create the `addQuestion` function that will be responsible for asking the user to input a single question and answer pair. For now, your code will not store the questions and their answers. This function is only for producing the interface.

Design your `main` function so that it asks the user to choose between creating a question or exiting the program. It should call the `addQuestion` function when the user asks to create a question and exits otherwise.

Save your code in the file called `quizgen.cc`.

## Hints
For this project, it is a good idea to use strings when getting user input to avoid using `cin.ignore` that tends to be confusing. 

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
void showGreeting(string name) {
  ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the distance formula
// sqrt((x1-x2)^2 + (y1-y2)^2)
double dist = sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
```
