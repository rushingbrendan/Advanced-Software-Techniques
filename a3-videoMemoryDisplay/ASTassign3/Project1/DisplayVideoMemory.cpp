/*
* FILE : DisplayVideoMemory.cpp
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



/*
* FUNCTION : ~videoMatrix
*
* DESCRIPTION : This function is a destructor for the videoMatrix class

*
* PARAMETERS :none
* RETURNS : none
*/
VideoMatrix::~VideoMatrix(void) {

	printf("\nVideoMatrix class destroyed");

}//eo VideoMatrix::~VideoMatrix(void) {




 /*
 * FUNCTION : VideoMatrix
 *
 * DESCRIPTION : This function is a constructor for the videoMatrix class
					sets x and y to 0. It also clears the video array.

 *
 * PARAMETERS :none
 * RETURNS : none
 */
VideoMatrix::VideoMatrix(void) {

	x = 0;
	y = 0;

	for (int i = 0; i < MAX_ROWS; i++) {

		for (int j = 0; j < MAX_COLS; j++) {
			video[i][j] = ' ';
		}
	}


}//eo VideoMatrix::~VideoMatrix(void) {




 /*
 * FUNCTION : DisplayVideoMemory
 *
 * DESCRIPTION : This function displays the video memory to the screen
					The video memory is a 2d matrix with row and column.

 *
 * PARAMETERS :none
 * RETURNS : none
 */
void VideoMatrix::DisplayVideoMemory (void)
{
int i = 0, j = 0;

	printf ("Video memory holds:\n");

	printf ("   ");
	for (i = 0; i < MAX_COLS; i++) {	// constant that needs definition
		if ((i % 10) == 0)
			printf ("%d", i / 10);
		else
			printf (" ");
	}	/* end for */
	printf ("\n");

	printf ("   ");
	for (i = 0; i < MAX_COLS; i++) {
		printf ("%d", i % 10);
	}	/* end for */
	printf ("\n");

	for (i = 0; i < MAX_ROWS; i++) {	// constant that needs definition
		printf ("%02d ", i);
		for (j = 0; j < MAX_COLS; j++) {
			printf ("%c", video[i][j]);	// private data member
		}
		printf ("\n");
	}
	printf ("\n\n");
}




/*
* FUNCTION : ClearScreen
*
* DESCRIPTION : This function clears the screen by setting every variable in the array to blank

*
* PARAMETERS :none
* RETURNS : none
*/
void VideoMatrix::ClearScreen(void){

	int i = 0;
	int j = 0;

	for (i = 0; i < MAX_ROWS; i++) {

		for (j = 0; j < MAX_COLS; j++) {
			video[i][j] = ' ';
		}
	}
}//eo clear screen





 /*
 * FUNCTION : setCursorPosition
 *
 * DESCRIPTION :	This function takes an input value for x and y and sets the current
					cursor position in the video array.

 *
 * PARAMETERS :int inputY, int inputX
 * RETURNS : int success or fail
 */
int VideoMatrix::SetCursorPosition( int inputY, int inputX) {

	if ((inputX < 0) || (inputX > MAX_ROWS)) {

		return FAILURE;
	}

	if ((inputY < 0) || (inputY > MAX_COLS)) {

		return FAILURE;
	}

	x = inputX;
	y = inputY;


	return SUCCESS;

}//eo int video::setCursorPosition(int inputX, int inputY) {




 /*
 * FUNCTION : outputString
 *
 * DESCRIPTION :	This function takes an input cstring and outputs it to the screen
					on the place that the cursor has been set to.

 *
 * PARAMETERS :const char* inputString
 * RETURNS : none
 */
void VideoMatrix::OutputString(const char* inputString) {

	int currentColumn = y;
	int currentRow = x;

	while (*inputString != '\0') {

		video[currentRow][currentColumn] = *inputString; //copy character

		currentColumn++;	//increment current column
		if (currentColumn >= MAX_COLS) {

			currentColumn = 0;

			currentRow++;
			if (currentRow >= MAX_ROWS) {	

				ScrollScreen();
				currentRow = 0;

			}//eo if (currentRow >= MAX_ROWS) {
		}//eo if (currentColumn >= MAX_COLS) {

		inputString++;

	}//eo while (*inputString != '\0') {

}//eo void videoMatrix::outputString(const char* inputString) {





 /*
 * FUNCTION : scrollScreen
 *
 * DESCRIPTION :	This function fixes the display output when the text string
					is longer than the width of the screen.

 *
 * PARAMETERS :none
 * RETURNS : none
 */
void VideoMatrix::ScrollScreen(void) {

	char* ptrSource = video[1];
	char* ptrDestination = video[0];
	
	for (int i = 1; i < (MAX_ROWS - 1); i++) {

		for (int x = 0; x < (MAX_ROWS - 2); x++) {

			*ptrDestination = *ptrSource;
			ptrDestination++;
			ptrSource++;

		}//eo for (int x = 0; x < (MAX_ROWS - 2); x::) {

	}//eo for (int i = 1; i < (MAX_ROWS - 1); i++) {


}//eo void videoMatrix::scrollScreen(void) {