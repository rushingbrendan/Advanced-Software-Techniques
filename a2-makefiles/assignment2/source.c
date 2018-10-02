/*  
*  FILE          : source.c 
*  PROJECT       : PROG1165 - Advanced System Programming - Assignment #2
*  PROGRAMMER    : Brendan Rushing
*  FIRST VERSION : 2018-06-17
*  DESCRIPTION   : 
*	This assignment verifys a random number against user input
*/

//INCLUDE FILES

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//EO INCLUDE FILES

//CONSTANTS


#define TOO_HIGH 1
#define TOO_LOW -1
#define CORRECT 0

#define MAX_RANDOM_VALUE 10


#pragma warning(disable:4996)

//EO CONSTANTS






int main(int argc, char *argv[]) {

	int randomNumber = 0;
	int userGuess = 0;
	srand(time(0));



	randomNumber = rand();
	randomNumber = randomNumber % MAX_RANDOM_VALUE;


	printf("\n Enter Random Number Guess: ");
	scanf("%d", &userGuess);

	if (userGuess == randomNumber){

		return CORRECT;

	}
	
	else if (userGuess > randomNumber){
		return TOO_HIGH;

	}

	else{

		return TOO_LOW;
	}



}// eo int main(int argc, char *argv[])
