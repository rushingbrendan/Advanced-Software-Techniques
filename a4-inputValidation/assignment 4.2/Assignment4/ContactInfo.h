/*
*  FILE          : ContactInfo.h
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
#include <iostream>
#include <regex>
#include <string>
//eo INCLUDE


//CONSTANTS
#define MAX_NAME_SIZE		30
#define MAX_STREET_SIZE		60
#define MAX_CITY_SIZE		60
#define POSTAL_CODE_LENGTH	 7
#define MAX_PROVINCE_LENGTH	 2
#define NUM_PROVINCES		13


#pragma once
//eo CONSTANTS



class ContactInfo
{
public:
	ContactInfo();
	~ContactInfo();

	void PrintInfo();

	bool SetName(std::string newName);
	std::string GetName() { return Name; }

	bool SetStreetAddress(std::string newStreetAdddress);
	std::string GetStreetAddress() { return StreetAddress; }

	bool SetCity(std::string newCity);
	std::string GetCity() { return City; }
	
	bool SetProvince(std::string newProvince);
	std::string GetProvince() { return Province; }
	
	bool SetPostalCode(std::string newPostalCode);
	std::string GetPostalCode() { return PostalCode; }
	
	bool SetPhoneNumber(std::string newPhoneNumber);
	std::string GetPhoneNumber() { return PhoneNumber; }

private:
	std::string Name;
	std::string StreetAddress;
	std::string City;
	std::string Province;
	std::string PostalCode;
	std::string PhoneNumber;
};