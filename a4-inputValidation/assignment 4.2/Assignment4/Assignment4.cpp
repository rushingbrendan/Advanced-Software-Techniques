/*
*  FILE          : Assignment4.cpp
*  PROJECT       : PROG1165 -  Advanced Software Techniques - Assignment #4
*  PROGRAMMER    : Brendan Rushing, Alex Kozak, Attila Katona, Josh Rogers
*  FIRST VERSION : 2018-07-08
*  DESCRIPTION   :
*	Create a program that takes input for an address book (of people, not businesses), validates the input, and stores the data in an array.
Once the user has entered the desired number of entries, the address book should be displayed in its entirety.

The data stored consists of:
Name (maximum length 30 characters)
Street Address (maximum length 60 characters)
City (maximum length 60 characters)
Province (in the format of a 2 character long Canadian province abbreviation used by Canada Post)
Postal Code (in the format of a Canadian Postal Code)
Phone Number, including area code
As noted earlier, the specific requirements for input validation will be provided after the first deadline.
It is a compilation of all submitted requirements.
You must prompt the user in a user-friendly way.
This requires that the prompt be informative but not overbearing.
If the user enters invalid input, an error message must be displayed indicating what the problem is.
The user must be given an option as to whether to skip entering this part of the address book entry (e.g. skip the Address and continue with the City) or to try again.
The array of addresses is of size 10.
The user will be permitted to enter up to 10 entries.
If the user chooses to end entry early, they can specify this by pressing ENTER as the first and only character of the name (this is the lone exception to the "pressing ENTER skips a component" requirement).
Once the user has done 10 entries or has chosen to end entry early, the program will then display the contents of the address book, three entries on a page.
Each entry will be five lines in size. The lines must be in the following format:
Fred Flintstone
11 Cobblestone Lane
Bedrock, ON, N2Y 3E8
519-555-1212
++++++++++++
Paginate your output properly (the user should not have to scroll to see output of a single address book entry.
Do not use regular expressions or any third-party libraries for this assignment.
When the program starts up, display the name (string) that your group has been assigned after Milestone 1.
This will uniquely identify your assignment. Do not put any other identifying information (e.g. "Fred's Address Book) in the program.
Call your executable file astA4.exe.


*/


//INCLUDE FILES
#include "ContactInfo.h"
//eo INCLUDE


//CONSTANTS
#define NUM_ADRESSES 10
//eo CONSTANTS


//PROTOTYPES
void testCase();
std::string getInput(std::string itemName);
//eo PROTOTYPES




int main()
{
	bool isTest = false;
	int numAddresses = 0;
	if (isTest) { testCase(); }

	ContactInfo addressBook[NUM_ADRESSES];
	std::string userInput;

	std::cout << "Team ID: 2772\n" << std::endl;

	for (int i = 0; i < NUM_ADRESSES; i++)
	{
		std::cout << "Press enter to end input.\nEnter Name: ";
		std::getline(std::cin, userInput);
		if (userInput == "")
		{
			numAddresses = i - 1;
			i = NUM_ADRESSES;
		}
		else
		{			
			while (userInput != "" && !addressBook[i].SetName(userInput))
			{
				userInput = getInput("Name");
			} 

			do
			{
				userInput = getInput("Street Address");
			} while (userInput != "" && !addressBook[i].SetStreetAddress(userInput));

			do
			{
				userInput = getInput("City");
			} while (userInput != "" && !addressBook[i].SetCity(userInput));

			do
			{
				userInput = getInput("Province");
			} while (userInput != "" && !addressBook[i].SetProvince(userInput));

			do
			{
				userInput = getInput("Postal Code");
			} while (userInput != "" && !addressBook[i].SetPostalCode(userInput));

			do
			{
				userInput = getInput("Phone Number");
			} while (userInput != "" && !addressBook[i].SetPhoneNumber(userInput));

			std::cout << std::endl;
			numAddresses++;
		}		
	}

	for (int i = 0; i <= numAddresses; i++)
	{
		if (i != 0 && i % 3 == 0)
		{
			std::cout << "Press Enter to continue..." << std::endl;
			std::cin;
		}
		std::cout << std::endl;
		addressBook[i].PrintInfo();		
	}

	return 0;

}//eo main




 /*
 * FUNCTION : getInput
 *
 * DESCRIPTION : This function gets input from user
 *
 * PARAMETERS : string
 *
 *
 * RETURNS : string
 */
std::string getInput(std::string itemName)
{
	std::string userInput;
	
	std::cout << "Enter " << itemName << ": ";
	std::getline(std::cin, userInput);

	return userInput;
}


/*
* FUNCTION : testCase
*
* DESCRIPTION : This function is a test harness for the application
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void testCase()
{
	ContactInfo c = ContactInfo();

	c.SetName("Daniel");
	c.SetName("ThisIsANameThatIsTooLongToBeValidSinceItIsOverTheMaximumNumberOfCharacters");
	c.SetName("Name With Spaces");
	c.SetName("N4M3 W1TH NUM83R5");
	c.SetName("");
	c.SetName(";'^%@#");

	std::cout << std::endl;

	c.SetCity("Toronto");
	c.SetCity("ThisIsACityThatIsTooLongToBeValidSinceItIsOverTheMaximumNumberOfCharacters");
	c.SetCity("Valid City With Spaces");
	c.SetCity("");
	c.SetCity(";'^%@#");

	std::cout << std::endl;

	c.SetPhoneNumber("555-555-5555");
	c.SetPhoneNumber("555-555-5555-555-555");
	c.SetPhoneNumber("555-555-55555");
	c.SetPhoneNumber("555-555");
	c.SetPhoneNumber("555-555-555A");
	c.SetPhoneNumber("ABC123");
	c.SetPhoneNumber("");
	c.SetPhoneNumber(";'^%@#");

	std::cout << std::endl;

	c.SetProvince("ON");
	c.SetProvince("AB");
	c.SetProvince("LLAMA");
	c.SetProvince("A");
	c.SetProvince("@@");
	c.SetProvince("");
	c.SetProvince(";'^%@#");

	std::cout << std::endl;

	c.SetPostalCode("T1A-1A1");
	c.SetPostalCode("A1A1A1");
	c.SetPostalCode("A1A 1A1");
	c.SetPostalCode("A1A-1A12");
	c.SetPostalCode("A1A-1A");
	c.SetPostalCode("G1A-1A1");
	c.SetPostalCode("");
	c.SetPostalCode(";'^%@#");

	std::cout << std::endl;

	c.SetStreetAddress("223 Imaginary Lane");
	c.SetStreetAddress("Valid Address");
	c.SetStreetAddress("223 Imaginary");
	c.SetStreetAddress("223");
	c.SetStreetAddress("@@ Fake Street");
	c.SetStreetAddress("");
	c.SetStreetAddress(";'^%@#");

	std::cout << std::endl;

	c.PrintInfo();
}