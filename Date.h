// a.) Robert James Castleberry
// b.) Complete
// c.) Date.h is the Date class specification file.
#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

// Declares the Date class.
class Date
{
	// Declares private data members.
	private:
		int month,	// Declares the month member variable for use as a member function parameter.
			day,	// Declares the day member variable for use as a member function parameter.
			year;	// Declares the year member variable for use as a member function parameter.

	// Declares public member functions.
	public:
		// Constructor.
		Date();

		// Assigns validated input values to the private data members.
		bool setDate(int, int, int);

		// Prints a date in various specific formats.
		void printFormat1();
		void printFormat2();
		void printFormat3();

		// Converts integer month values to strings.
		string getMonthName();

};
#endif