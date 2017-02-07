// a.) Robert James Castleberry
// b.) Complete
// c.) This program processes input data regarding the amount of food eaten
// by monkeys at a zoo and prints it in an easily viewed format.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_DAYS = 7; // Number of days in a week is constant.
const int NUM_MONKEYS = 3;	// Number of monkeys is apparently also constant.

double average(double []);
double least(double []);
double largest(double []);

void setMonkeyFood(double [][NUM_DAYS+1]); // Function prototype for setting monkey food data into an array.
void printReport(double [][NUM_DAYS+1]); // Function prototype for printing a report.
double getAvgFood(double [][NUM_DAYS+1]); // Function prototype for averaging food eaten per day.
double getLeastFood(double [][NUM_DAYS+1]);	// Function prototype for getting the least food eaten.
double getMostFood(double [][NUM_DAYS+1]);	// Function prototype for getting the most food eaten.
string getDayName(int); // Function prototype for converting day integers to their respective names.

int main()
{
	double monkeyFood[NUM_MONKEYS+1][NUM_DAYS+1]; // Array for storing monkey food consumption amounts.
	
	// Calls the set function so the user can input data.
	setMonkeyFood(monkeyFood);
	// Calls function to print report.
	printReport(monkeyFood);

	// Creates a pause until the user is finished viewing the report.
	cin.ignore();
	cout << "\nPress [Enter] to end the program: ";
	cin.get();

	return 0;
}

// Function for setting monkey food data into an array.
void setMonkeyFood(double mf[][NUM_DAYS+1])
{
	int indexMonkey,
	    indexDay;

	// Takes input for monkeyFood array.
	for (indexMonkey = 1; indexMonkey <= NUM_MONKEYS; indexMonkey++)
	{	
		cout << "\n\n"; // Inserts a gap between sets of input for monkeys.

		for (indexDay = 1; indexDay <= NUM_DAYS; indexDay++)
		{
			cout << "Enter pounds of food eaten by monkey " << indexMonkey
				 << " on " << getDayName(indexDay) << ": ";
			cin  >> mf[indexMonkey][indexDay];

			while (mf[indexMonkey][indexDay] < 0)
			{
				cout << "\nPounds of food eaten cannot be a negative number!";
				cout << "Enter pounds of food eaten by monkey " << indexMonkey
					 << " on " << getDayName(indexDay) << ": ";
				cin  >> mf[indexMonkey][indexDay];				
			}
		}
	}
}

// Function for averaging food eaten per day.
double getAvgFood(double mf[][NUM_DAYS+1])
{
	double total = 0.0;	// Running total.
	double average;	// Stores average value for returning.
	int indexMonkey,	// Index for monkey row.
		indexDay;	// Index for day column.
	
	// Totals food eaten in a week.
	for (indexMonkey = 1; indexMonkey <= NUM_MONKEYS; indexMonkey++)
	{
		for (indexDay = 1; indexDay <= NUM_DAYS; indexDay++)
		{
			total += mf[indexMonkey][indexDay];
		}
	}
	
	// Calculates average.
	average = total / 7;

	// Returns average.
	return average;
}

// Function for calculating most food eaten in a day.
double getMostFood(double mf[][NUM_DAYS+1])
{
	double most = mf[1][1]; // Stores most food eaten.
	int indexMonkey, // Index for monkey row.
		indexDay;	// Index for day column.

	// Calculates most food eaten.
	for (indexMonkey = 1; indexMonkey <= NUM_MONKEYS; indexMonkey++)
	{
		for (indexDay = 1; indexDay <= NUM_DAYS; indexDay++)
		{
			if (mf[indexMonkey][indexDay] > most)
			{
				most = mf[indexMonkey][indexDay];
			}
		}
	}

	// Returns most food eaten.
	return most;
}

// Function for calculating least food eaten.
double getLeastFood(double mf[][NUM_DAYS+1])
{
	double least = mf[1][1]; // Stores least food eaten.
	int indexMonkey, // Index for monkey row.
		indexDay;	// Index for day column.

	// Calculates least food eaten.
	for (indexMonkey = 1; indexMonkey <= NUM_MONKEYS; indexMonkey++)
	{
		for (indexDay = 1; indexDay <= NUM_DAYS; indexDay++)
		{
			if (mf[indexMonkey][indexDay] < least)
			{
				least = mf[indexMonkey][indexDay];
			}
		}
	}

	// Returns least food eaten.
	return least;
}

// Function for converting day integers to their abbreviated string equivalent.
string getDayName(int x)
{
	string dayNames[NUM_DAYS+1] = // Initializes array of day names.
	{ "", "Sun", "Mon", "Tue", "Wed", "Thu",
	"Fri", "Sat" };
	string dayName; // Variable for storing day name to be returned.
	int indexName = x; // Index for dayNames array.
	
	dayName = dayNames[indexName]; // Assigns appropriate day name.

	return dayName;	// Returns appropriate day name.
}

// Function for printing report.
void printReport(double mf[][NUM_DAYS+1])
{
	int indexMonkey, // Index for monkey row.
	    indexDay;	// Index for day column.

	// Clears screen so report can be viewed separate from input.
	cout << string(50, '\n');
	
	// Prints column titles.
	cout << "Monkey   Sun   Mon   Tue   Wed   Thu   Fri   Sat";

	// Prints user input data.
	for (indexMonkey = 1; indexMonkey <= NUM_MONKEYS; indexMonkey++)
	{	
		cout << "\n" << right << setw(6) << indexMonkey;

		for (indexDay = 1; indexDay <= NUM_DAYS; indexDay++)
		{
			cout << fixed << showpoint << setprecision(1);
			cout << "   " << mf[indexMonkey][indexDay];			
		}
	}

	// Prints calculated min/max and average food eaten values.
	cout << fixed << showpoint << setprecision(1);
	cout << "\nThe average food eaten per day by all monkeys          :" << right << setw(13) << getAvgFood(mf);
	cout << "\nThe least amount of food eaten in a day by any monkey  :" << right << setw(13) << getLeastFood(mf);
	cout << "\nThe largest amount of food eaten in a day by any monkey:" << right << setw(13) << getMostFood(mf);
}