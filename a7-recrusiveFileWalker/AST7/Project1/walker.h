/*
*  FILE          : walker.h
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



//PRAGMA
#pragma once
#pragma warning (disable: 4996)
//eo PRAGMA


//INCLUDE
#include <string>
//eo INCLUDE


//CONSTANTS
#define MAX_FILE_NAME_LENGTH 1000
#define MAX_PATH_NAME_LENGTH 100
//eo CONSTANTS




/*
* NAME: Walker
* PURPOSE: This class has functions to walk through file directories in Windows

*/
class Walker {


private:

	int regexCount;

public:

	int WalkDirectory(char *baseDirectory, std::string regexPattern, int regexCount);
	int GetRegexCount(void);

};