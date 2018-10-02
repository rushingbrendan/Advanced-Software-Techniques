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




//INCLUDE FILES
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#include "walker.h"
#include <string>
#include <regex>
//eo INCLUDE FILES



/*
* FUNCTION : walkDirectory
*
* DESCRIPTION : This function is walks through a Windows file system directory
*
* PARAMETERS : char *baseDirectory
*
*
* RETURNS : none
*/
int Walker::WalkDirectory(char *baseDirectory, std::string regexPattern, int regexCount) {

	char path[MAX_FILE_NAME_LENGTH];
	struct dirent *dp;
	DIR *dir = opendir(baseDirectory);


	// Return if cannot open directory
	if (!dir) {

		return regexCount;

	}//eo if (!dir) {


	 //if directory is not NULL then...
	while ((dp = readdir(dir)) != NULL) {

		if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {

			if (regex_match(dp->d_name, std::regex(regexPattern)) == true) {

				printf("%s\n", dp->d_name);	//print string if match
				regexCount++;

			}//eo if (regex_match(dp->d_name, std::regex(regexPattern)) == true) {


			 // Construct new directory from base directory
			strcpy(path, baseDirectory);
			strcat(path, "/");
			strcat(path, dp->d_name);

			try {

				WalkDirectory(path, regexPattern, 0);
			}

			catch (std::regex_error) {

				printf("\nRegex Error");
			}


		}//eo if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)

	}//eo while ((dp = readdir(dir)) != NULL)




	 //close directory
	closedir(dir);

	return regexCount;

}//eo void walkDirectory(char *basePath){







 /*
 * FUNCTION : GetRegexCount
 *
 * DESCRIPTION : This function returns the value of the regex count variable
 *
 * PARAMETERS : none
 *
 *
 * RETURNS : int regexcount
 */

int Walker::GetRegexCount(void) {

	return regexCount;

}