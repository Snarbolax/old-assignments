# QuizMaker Project Milestone 3

This is milestone 3 of the [QuizMaker Project][REDACTED].

# Requirements
We will create two functions that allow us to display the questions that have
been created and store the information to a text file.

## Displaying questions
Create a `display_questions` function that accepts two parameters: a `question`
array and its size. Take note that the size we refer to here is the number of
`question` objects inside the array. For example, if there were three `question`
objects in the array, it's size would be three. Do not confuse this with the
maximum number of elements in the array, which is 100.

The function should access each `question` object in the array according to the
size, and then display the corresponding text and answer. Take a look at the example
below that shows the expected screen output when `display_questions` is called.
This example assumes three questions were added to the array.

*Take note that the number and the word 'Answer' is not stored in the `question`
object*

### Sample output
```
Question and Answer list
1. Who is the mother of the COBOL programming language?
Answer: Grace Hopper
2. Who developed C++?
Answer: Bjarne Stroustrup
3. Who developed the Ruby programming language?
Answer: Yukihiro Matsumoto
```
## Saving questions
Create a `save_questions` function that accepts three parameters: a `question`
array, its size, and the filename. This function will save all elements in the
question array according to the size and store values into a text file using the
filename provided.

The text file needs to follow a certain format so that it can be read easily.
The first line should indicate how many `question` objects are in the array. For
every `question` object, the function should write a marker ([SQ]), the text, and
the answer into the file. Take a look at the example below that shows the file
that is produced when `save_questions` is called. This example uses the same
three examples for `display_questions`.

### Sample text file output
```
3
[SQ]
Who is the mother of the COBOL programming language?
Grace Hopper
[SQ]
Who developed C++?
Bjarne Stroustrup
[SQ]
Who developed the Ruby programming language?
Yukihiro Matsumoto
```

## Updated menu
The menu that your program uses should be updated to include the two new options
for displaying a question and saving it to a file. When the user selects the
option to save the file, it should ask the user to provide a filename. This
filename is used in calling the `save_questions` function. Take a look at the
sample output below.

### Sample output
```
Welcome to QuizMaker

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: a

Please enter your question: Who is the mother of the COBOL programming language?
Please enter the answer: Grace Hopper
Question added!

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: a

Please enter your question: Who developed C++?
Please enter the answer: Bjarne Stroustrup
Question added!

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: a

Please enter your question: Who developed the Ruby programming language?
Please enter the answer: Yukihiro Matsumoto
Question added!

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: b

Question and Answer list
1. Who is the mother of the COBOL programming language?
Answer: Grace Hopper
2. Who developed C++?
Answer: Bjarne Stroustrup
3. Who developed the Ruby programming language?
Answer: Yukihiro Matsumoto

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: c

What filename would you like to use? questions.txt
File saved successfully!

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: x

Invalid option

What would you like to do?
a. Create a question
b. Display questions
c. Save questions
d. Quit
Choice: d

Thank you for using QuizMaker!
```

Place the function prototypes and classes in `quiz.hpp`, the function implementations in `quiz.cpp`, and the main function in `quizgen.cpp`.

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

