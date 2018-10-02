/*
*  FILE          : ContactInfo.cpp
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
#include <cctype>
//eo INCLUDE FILES


//CONSTANTS
std::string validAccentCharacters("‡ËÏÚ˘¿»Ã“Ÿ·ÈÌÛ˙˝¡…Õ”⁄›‚ÍÓÙ˚¬ Œ‘€„Òı√—’‰ÎÔˆ¸ˇƒÀœ÷‹üÂ≈Ê∆úåÁ«–¯ÿø°ﬂ");
std::string alpha("ABCDEFGHIJKLMNOPQRTSUVWXYZabcdefghijklmnopqrtsuvwxyz");
std::string numeric("0123456789");
#pragma warning(suppress: 4129)
std::string special("!.,/?()[]{}\|;:\'\"");
std::string spacer("- ");
std::string validProvinces[NUM_PROVINCES] = { "AB", "BC", "MB", "NB", "NL", "NS", "NU", "ON", "PE", "QC", "SK", "YT" , "NT"};
#pragma warning( disable : 4244)
//eo CONSTANTS


//PROTOTYPES
bool isValidPostalCodeFirstLetter(std::string province, char firstLetter);
void printError(std::string invalidInput);
bool isAlpha(char c);
bool isNumeric(char c);
bool isSpecial(char c);
bool isSpacer(char c);
bool isValidAccent(char c);
//eo PROTOTYPES



/*
* FUNCTION : ContactInfo
*
* DESCRIPTION : This function is a default constructor for ContactInfo class
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
ContactInfo::ContactInfo()
{
	Name = "";
	StreetAddress = "";
	City = "";
	Province = "";
	PostalCode = "";
	PhoneNumber = "";
}





/*
* FUNCTION : ~ContactInfo
*
* DESCRIPTION : This function is a destructor for ContactInfo class
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
ContactInfo::~ContactInfo()
{
}


/*
* FUNCTION : SetName
*
* DESCRIPTION : This function sets the name variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : none
*/
bool ContactInfo::SetName(std::string newName)
{
	bool isValid = newName.size() <= MAX_NAME_SIZE && newName.size() > 0; 
	for (int i = 0; i < newName.length() && isValid; i++)
	{
		isValid = isAlpha(newName[i]) || newName[i] == ' ' || isValidAccent(newName[i]);
	}
	if (isValid)
	{
		Name = newName;
	}
	else
	{
		printError(newName);
	}
	return isValid;
}



/*
* FUNCTION : SetStreetAddress
*
* DESCRIPTION : This function sets the street address variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : bool
*/
bool ContactInfo::SetStreetAddress(std::string newStreetAdddress)
{
	bool isValid = newStreetAdddress.size() <= MAX_STREET_SIZE && newStreetAdddress.size() > 0;
	
	int numSpaces = 0;
	int x = atoi(newStreetAdddress.c_str());

	if (x == 0 || newStreetAdddress.length() == log10(x))	{ isValid = false; }
	else
	{
		int y = log10(x) + 1;
		std::string tempString = newStreetAdddress.substr(y, newStreetAdddress.length() - y);

		for (int i = 0; i < tempString.length() && isValid; i++)
		{
			if (tempString[i] == ' ')
			{
				numSpaces++;
			}
			isValid = isAlpha(tempString[i]) || tempString[i] == ' ';
		}
	}
	isValid = numSpaces >= 2;
	if (isValid)
	{
		StreetAddress = newStreetAdddress;
	}
	else
	{
		printError(newStreetAdddress);
	}

	return isValid;
}



/*
* FUNCTION : SetCity
*
* DESCRIPTION : This function sets the city variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : bool
*/
bool ContactInfo::SetCity(std::string newCity)
{
	bool isValid = newCity.length() <= MAX_CITY_SIZE && newCity.length() > 3;
	for (int i = 0; i < newCity.length() && isValid; i++)
	{
		isValid = isAlpha(newCity[i]) || newCity[i] == ' ' || isValidAccent(newCity[i]);
	}
	if (isValid)
	{
		City = newCity;
	}
	else
	{
		printError(newCity);
	}

	return isValid;
}




/*
* FUNCTION : SetProvince
*
* DESCRIPTION : This function sets the province variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : bool
*/
bool ContactInfo::SetProvince(std::string newProvince)
{
	bool isValid = false;
	for (int i = 0; i < NUM_PROVINCES && !isValid; i++)
	{
		isValid = newProvince == validProvinces[i];
	}
	if (isValid)
	{
		Province = newProvince;
	}
	else
	{
		printError(newProvince);
	}

	return isValid;
}




/*
* FUNCTION : SetPostalCode
*
* DESCRIPTION : This function sets the postal code variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : bool
*/
bool ContactInfo::SetPostalCode(std::string newPostalCode)
{
	bool isValid = newPostalCode.length() == POSTAL_CODE_LENGTH;
	bool isLetter = true;

	if (isValid)
	{
		isValid = isValidPostalCodeFirstLetter(Province, toupper(newPostalCode[0]));
	}
	for (int i = 0; i < newPostalCode.length() && isValid; i++)
	{
		if (i == 3)
		{
			if (!isSpacer(newPostalCode[i]))
			{
				isValid = isNumeric(newPostalCode[i]);
				isLetter = !isLetter;
			}
		}
		else if (isLetter)
		{
			isValid = isAlpha(newPostalCode[i]);
			newPostalCode[i] = toupper(newPostalCode[i]);
			isLetter = !isLetter;
		}
		else
		{
			isValid = isNumeric(newPostalCode[i]);
			isLetter = !isLetter;
		}
	}
	if (isValid)
	{
		PostalCode = newPostalCode;
	}
	else
	{
		printError(newPostalCode);
	}

	return isValid;
}




/*
* FUNCTION : SetPhoneNumber
*
* DESCRIPTION : This function sets the phone number variable in the ContactInfo class
*
* PARAMETERS : string
*
*
* RETURNS : bool
*/
bool ContactInfo::SetPhoneNumber(std::string newPhoneNumber)
{
	bool isValid = newPhoneNumber.size() == 12;
	for (int i = 0; i < newPhoneNumber.length() && isValid; i++)
	{
		isValid = isNumeric(newPhoneNumber[i]) || ((i==3 || i == 7) && newPhoneNumber[i] == '-');
	}
	if (isValid)
	{
		PhoneNumber = newPhoneNumber;
	}
	else
	{
		printError(newPhoneNumber);
	}

	return isValid;
}




/*
* FUNCTION : printError
*
* DESCRIPTION : This function prints the error message to the screen.
*
* PARAMETERS : string
*
*
* RETURNS : none
*/
void printError(std::string invalidInput)
{
	std::cout << invalidInput << " is not a valid input" << std::endl;
	std::cout << "Press ENTER to Skip the component." << std::endl;
}


/*
* FUNCTION : PrintInfo
*
* DESCRIPTION : This function prints all variable information to the screen
*
* PARAMETERS : none
*
*
* RETURNS : none
*/
void ContactInfo::PrintInfo()
{
	std::cout << Name << std::endl << StreetAddress << std::endl << City << ", " << Province << ", " << PostalCode << std::endl << PhoneNumber << std::endl << "++++++++++++" << std::endl;
}


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
bool isAlpha(char c)
{
	return alpha.find(c) != std::string::npos;
}


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
bool isNumeric(char c)
{
	return numeric.find(c) != std::string::npos;
}



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
bool isSpecial(char c)
{
	return special.find(c) != std::string::npos;
}



/*
* FUNCTION : isSpacer
*
* DESCRIPTION : This function checks to see if there is spacer
*
* PARAMETERS : char
*
*
* RETURNS : bool
*/
bool isSpacer(char c)
{
	return spacer.find(c) != std::string::npos;
}


/*
* FUNCTION : isValidAccent
*
* DESCRIPTION : This function checks to see if there is a valid accent
*
* PARAMETERS : char
*
*
* RETURNS : bool
*/
bool isValidAccent(char c)
{
	return validAccentCharacters.find(c) != std::string::npos;
}



/*
* FUNCTION : isValidPostalCodeFirstLetter
*
* DESCRIPTION : This function checks to see if the first letter in Postal code is valid
*
* PARAMETERS : string, char
*
*
* RETURNS : bool
*/
bool isValidPostalCodeFirstLetter(std::string province, char firstLetter)
{
	bool isValid = true;
	if (province != "")
	{
		switch (firstLetter)
		{
		case 'A':
		{
			if (province != "NL")
			{
				isValid = false;
			}
			break;
		}
		case 'B':
		{
			if (province != "NS")
			{
				isValid = false;
			}
			break;
		}
		case 'C':
		{
			if (province != "PE")
			{
				isValid = false;
			}
			break;
		}
		case 'E':
		{
			if (province != "NB")
			{
				isValid = false;
			}
			break;
		}
		case 'G':
		case 'H':
		case 'J':
		{
			if (province != "QC")
			{
				isValid = false;
			}
			break;
		}
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'P':
		{
			if (province != "ON")
			{
				isValid = false;
			}
			break;
		}
		case 'R':
		{
			if (province != "MB")
			{
				isValid = false;
			}
			break;
		}
		case 'S':
		{
			if (province != "SK")
			{
				isValid = false;
			}
			break;
		}
		case 'T':
		{
			if (province != "AB")
			{
				isValid = false;
			}
			break;
		}
		case 'V':
		{
			if (province != "BC")
			{
				isValid = false;
			}
			break;
		}
		case 'X':
		{
			if (province != "NU" && province != "NT")
			{
				isValid = false;
			}
			break;
		}
		case 'Y':
		{
			if (province != "YT")
			{
				isValid = false;
			}
			break;
		}
		}
	}
	return isValid;
}