
/*
* FILE : DisplayVideoMemory.h
* PROJECT : PROG1165 - Advanced Software Techniques - Assignment 3
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018 - 05 - 25
* DESCRIPTION :
Implement a complete solution to the video simulation discussed in class (see lecture slides).
You may implement this as a C++ class or using C functions.
(If using C++, implement the class with the video memory, current row, and current column as private data members of the class.)
Use the array linearization (using pointers for extra efficiency) techniques discussed in the lecture wherever applicable (this is the point of the assignment).
Note: You DO NOT need to implement the shape plotting function.
You will add one more method/function to your solution, DisplayVideoMemory(). The C++ method is provided as an extra file with this assignment.
This function will allow you to output to the Windows console the current contents of your video memory to prove your API functions are working correctly.
You will note that we revert back to the array processing here, as we need to know about our row/column offsets for the processing of the visual output.
This function will output the row and column offsets so that you can easily verify that your algorithms are actually doing the work they are meant to do.
This is a good example of a "test harness" function - some code that helps you verify that your code is doing the right work.
Every algorithm needs test harness code. An example of a test harness is provided as an extra file with this assignment.
Consider it a MINIMAL test harness for your simulation. It is expected that your testing goes beyond this.
Make your video dimensions equal to 40 columns and 24 rows.
*/




//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
//eo INCLUDE FILES





//CONSTANTS
#define MAX_ROWS 24
#define MAX_COLS 40
#define SUCCESS 1
#define FAILURE 0
//eo CONSTANTS



class VideoMatrix {


private:

	char video[MAX_ROWS][MAX_COLS];
	int x;
	int y;


public:

	VideoMatrix(void);
	~VideoMatrix(void);
	void DisplayVideoMemory(void);
	void ClearScreen(void);
	int SetCursorPosition(int, int);
	void OutputString(const char* inputString);
	void ScrollScreen(void);

};