// a.) Robert James Castleberry
// b.) Complete
// c.) This program uses the Date class.
// The Date class declaration is in file Date.h.
// The Date class member functions are in Date.cpp.
// These files should all be combined into a project.
#include "Date.h"
#include <iostream>
using namespace std;

// Main function of the program. Receives, validates, and then prints a user input date.
int main()
{
	Date date1;	// Declares a Date object.

	int month1,	// Declares an integer variable for use as a Date function parameter, month.
		day1,	// Declares an integer variable for use as a Date function parameter, day.
		year1;	// Declares an integer variable for use as a Date function parameter, year.

	// Asks for and receives input.
	cout << "Please enter the month: ";
	cin >> month1;
	cout << endl << "Please enter the day: ";
	cin >> day1;
	cout << endl << "Please enter the year: ";
	cin >> year1;

	// Loops until valid input is received.
	while (!date1.setDate(month1, day1, year1))
	{
		// Alerts user of invalid input and describes required format.
		cout << endl << "Invalid entry! Please enter a valid date." << endl;
		cout << "The month should be an integer within [1, 12]" << endl;
		cout << "The day should be an integer within [1, 31]" << endl;
		cout << "The year should be an integer within [1950, 2020]" << endl;

		// Asks for and receives new input.
		cout << endl << "Please enter the month: ";
		cin >> month1;
		cout << endl << "Please enter the day: ";
		cin >> day1;
		cout << endl << "Please enter the year: ";
		cin >> year1;
	}

	// Prints the user input date in various specific formats.
	date1.printFormat1();
	date1.printFormat2();
	date1.printFormat3();

	// Creates a pause so the output can be viewed.
	cin.ignore();
	cout << "\nPress [Enter] to exit the program: ";
	cin.get();

	// End of program.
	return 0;
}