// a.) Robert James Castleberry
// b.) Complete
// c.) Date.cpp is the Date class function implementation file.
#include "Date.h"
#include <iostream>
using namespace std;

// Constructor for Date class.
Date::Date()
{
	month = 1;	// Initializes the month member variable.
	day = 1;	// Initializes the day member variable.
	year = 2001;	// Initializes the year member variable.
}


// Defines a function that validates a user input date before assigning its values.
bool Date::setDate(int mo, int dy, int yr)
{
	bool validData = true;	// Initializes a boolean variable for input validation and returning.
	
	// Validates input data and assigns values if validated.
	if (mo < 1 || mo > 12)
	{
		validData = false;
	}
	else if (dy < 1 || dy > 31)
	{
		validData = false;
	}
	else if (yr < 1950 || yr > 2020)
	{
		validData = false;
	}
	else
	{
		month = mo;
		day = dy;
		year = yr;
	}

	// Indicates input validation or invalidation.
	return validData;
}


// Defines a "get" member function that returns the name of a month as a string.
string Date::getMonthName()
{
	string monthName;	// Declares a string variable for storing the name of a month.

	// Determines the name of the month and assigns it as a string to be returned.
	if (month == 1)
	{
		monthName = "January";
	}
	else if (month == 2)
	{
		monthName = "February";
	}
	else if (month == 3)
	{
		monthName = "March";
	}
	else if (month == 4)
	{
		monthName = "April";
	}
	else if (month == 5)
	{
		monthName = "May";
	}
	else if (month == 6)
	{
		monthName = "June";
	}
	else if (month == 7)
	{
		monthName = "July";
	}
	else if (month == 8)
	{
		monthName = "August";
	}
	else if (month == 9)
	{
		monthName = "September";
	}
	else if (month == 10)
	{
		monthName = "October";
	}
	else if (month == 11)
	{
		monthName = "November";
	}
	else if (month == 12)
	{
		monthName = "December";
	}
	else
	{
		monthName = "Error!";
	}

	return monthName;
}


// Defines print functions for various specific formats.

// Defines the print function for the 1/1/2001 format.
void Date::printFormat1()
{
	cout << month << "/" << day << "/" << year << endl;
}

// Defines the print function for the January 1, 2001 format.
void Date::printFormat2()
{
	cout << getMonthName() << " " << day << ", " << year << endl;
}

// Defines the print function for the 1 January 2001 format.
void Date::printFormat3()
{
	cout << day << " " << getMonthName() << " " << year << endl;
}