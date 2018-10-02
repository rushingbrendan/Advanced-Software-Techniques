/*
*  FILE          : main.cpp
*  PROJECT       : PROG1165 - Advanced Software Techniques
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-07-31
*  DESCRIPTION   :
*	This assignment is a file walker. 
	It uses recursion to walk through windows directories
	and compares the files and folders to a regex match. 
	It prints out the matches.

	The first command line switch is the directory.
	The second command line switch is the regex pattern

	I used the dirent header Library file to use functions for Windows file system to work with directories
	Credit: https://github.com/tronkko/dirent	* Dirent interface for Microsoft Visual Studio
 *	Copyright (C) 2006-2012 Toni Ronkko

*/

//INCLUDE FILES
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#include "walker.h"
#include <string>
#include <regex>

//eo INCLUDE FILES



//CONSTANTS


//eo CONSTANTS



//PRAGMA
#pragma warning (disable: 4996)
//eo PRAGMA


//PROTOTYPES

//eo PROTOTYPES



int main(int argc, char* argv[])
{
	std::string regexPattern = { 0 };
	char directoryPath[MAX_PATH_NAME_LENGTH];
	Walker* myWalker = NULL;

	myWalker = new Walker;

	if (argc == 3) {

		strcpy(directoryPath, argv[1]);
		regexPattern = argv[2];

	}//eo if (argc == 3) {

	else {

		return EXIT_FAILURE;
	}

	try {

		myWalker->WalkDirectory(directoryPath, regexPattern, 0);
	}
	catch (std::exception &e) {

		printf("\nException found: %s", e.what());
	}


	if (myWalker->GetRegexCount() == 0) {

		printf("\nNo file or directory found.");
	}
	

	delete myWalker;
	return EXIT_SUCCESS;

}//eo main






