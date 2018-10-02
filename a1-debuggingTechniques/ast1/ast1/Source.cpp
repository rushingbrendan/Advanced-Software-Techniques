/*
*  FILE          : source.cpp
*  PROJECT       : PROG1165 - Advanced Software Techniques - Assignment #1
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-11
*  DESCRIPTION   :
*	This assignment is the implmentation of a simple error logging facility.
*/

//INCLUDE FILES


#include <string>
#include <cstring>
#include <cstdbool>
#include <stdbool.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include <windows.h>

//EO INCLUDE FILES


//CONSTANTS

#define FILE_NAME_LENGTH 200

#define TEXT_FILE
#define DEBUG_CONSOLE
#define PROGRAM_CONSOLE

#define ERROR_LOG_PATH "../ERROR/"


#pragma warning(disable:4996)

//EO CONSTANTS



bool LogError(std::string inputString);



/*
* FUNCTION : LogError
*
* DESCRIPTION : This function is receives a string and outputs the string to one of 3 options.
	1. Program console
	2. Debug window
	3. Text file
*
* PARAMETERS : std::string inputString
*
*
* RETURNS : bool: true or false
*/
bool LogError(std::string inputString) {

	std::string date = { 0 };
	std::string outputString = { 0 };
	std::string outputLocation = { ERROR_LOG_PATH "ErrorLog.txt" };
	
	//find current time and date
	time_t _tm = time(NULL);
	struct tm * curtime = localtime(&_tm);
	date = asctime(curtime);
	date = date.substr(0, date.size() - 1);

	outputString = date + " -- " + inputString + "\n";


#ifdef TEXT_FILE
	
	std::ofstream outfile(outputLocation, std::ios_base::app);


	if (!outfile.is_open()) {

		std::cout << "ERROR CREATING LOG FILE" << std::endl;

	}

	outfile << outputString;

	outfile.close();

#endif // TEXT_FILE



#ifdef PROGRAM_CONSOLE

	std::cout << outputString;


#endif // DEBUG

#ifdef DEBUG_CONSOLE

	OutputDebugStringA(outputString.c_str());

#endif // DEBUG

	return true;

}//eo int LogError(std::string inputString) {






int main(int argc, char *argv[]) {


	bool ageIsValid = false;

	do {

		long ret = 0;
		char *ptr = NULL;


		int age = 0;
		std::string errorMessage = { 0 };
		std::string inputBuffer = { 0 };

		std::cout << "Please enter age: ";

		std::getline(std::cin, inputBuffer);
		std::cout << std::endl;


		ret = strtol(&inputBuffer[0], &ptr, 10);

		age = atoi(&inputBuffer[0]);

		if (inputBuffer.empty()) {

			std::cout << "Input cannot be blank" << std::endl;

			if (!LogError("Input cannot be blank")) {

				std::cout << "ERROR with ErrorLog function" << std::endl;

			}//eo if (!LogError("Input cannot be blank")) {



		}//eo if (inputBuffer.size == 0) {

		else if (*ptr != NULL) {

			std::cout << "Input cannot be non-numeric" << std::endl;

			if (!LogError("Input cannot be non-numeric")) {

				std::cout << "ERROR with ErrorLog function" << std::endl;

			}//eo if (!LogError("Input cannot be non-numeric")) {

			
		}//eo if (ptr == NULL)

		else if (*ptr == NULL) {

			if ((age < 1) || (age > 110)) {

				std::cout << "Input is out of range" << std::endl;

				if (!LogError("Input is out of range")) {

					std::cout << "ERROR with ErrorLog function" << std::endl;

				}//eo if (!LogError("Input is out of range")) {


			}//eo if ((age < 1) || (age > 110)) {

			else {

				std::cout << "Thank You" << std::endl;
				ageIsValid = true;

			}//eo else


		}//eo else if ptr == null
			
		
	} while (!ageIsValid);

	
	return EXIT_SUCCESS;

}// eo int main(int argc, char *argv[])
