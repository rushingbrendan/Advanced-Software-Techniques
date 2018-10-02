/*
* FILE : TestHarness.cpp
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
#include "DisplayVideoMemory.h"
//eo INCLUDE FILES







int main (void)
{

	VideoMatrix screen;

	screen.ClearScreen();				// test API #1
	screen.OutputString ("top left corner");
	screen.DisplayVideoMemory();
	screen.SetCursorPosition (10, 5);	// test API #2
	screen.OutputString ("here's some text in the middle of the screen");	// test API #3
	screen.DisplayVideoMemory();
	screen.SetCursorPosition(35, 9);  // test API #2
	screen.OutputString ("here's text that will scroll the screen!");		// test API #3
	screen.DisplayVideoMemory();


	screen.SetCursorPosition(7, 7);  // test API #3
	screen.OutputString("Brendan Rushing is awesome this assignment is very good  :)");		// test API #3
	screen.DisplayVideoMemory();

	screen.SetCursorPosition(22, 23);  // test API #4
	screen.OutputString("bottom left corner test to see if the test rolls over to the top of the screen properly.");		// test API #3
	screen.DisplayVideoMemory();


	return EXIT_SUCCESS;
}
