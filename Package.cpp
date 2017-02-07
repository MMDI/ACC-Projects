// a.) Robert James Castleberry
// b.) Complete
// c.) This is the Package class implementation file.
#include "Package.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constructor.
Package::Package()
{
	weight = 0; // Initial weight.
	side1 = 0;	// Initial length.
	side2 = 0;	// Initial length.
	side3 = 0;	// Initial length.
}

// Defines Shipping structure for use in our cost array.
struct Shipping
{
	int weightShip;	// Stores weight thresholds.
	double costShip; // Stores price thresholds.

	//Constructor
	Shipping(int ws, double cs)
	{
		weightShip = ws;	// Stores weight thresholds.
		costShip = cs;	// Stores price thresholds.
	}
};

// Prompts for and receives input for package specifications.
void Package::setPack(int wt, int s1, int s2, int s3)
{
	weight = wt; // Sets weight.
	side1 = s1;	//Sets dimension.
	side2 = s2;	//Sets dimension.
	side3 = s3;	//Sets dimension.
}

// Searches for and returns the cost of shipping a package.
double Package::getCost()
{	
	Shipping costTable[15] = // Initializes array of structures for weight/cost thresholds.
	{ { 1, 1.50 }, { 2, 2.10 }, { 3, 4.00 }, { 5, 6.75 }, { 7, 9.90 },
	{ 10, 14.95 }, { 13, 19.40 }, { 16, 24.20 }, { 20, 27.30 }, { 25, 31.90 },
	{ 30, 38.50 }, { 35, 43.50 }, { 40, 44.80 }, { 45, 47.40 }, { 50, 55.20 } };
	
	int index = 0; // Index for search loop.
	int position = -1;	// Position of search.
	bool found = false;	// Flag for search success.
	// Search loop.
	while (index < 15 && !found)
	{	// Compares values and sets values accordingly.
		if (weight <= costTable[index].weightShip)
		{
			found = true;
			position = index;
		}
		// Increments index.
		index++;
	}
	// Returns appropriate cost.
	return costTable[position].costShip;
}

// Returns package weight.
int Package::getWeight()
{
	return weight;
}

// Prints the details of a transaction.
void Package::printTrans(int tn, string s, double c)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTransaction:" << right << setw(11) << tn;
	cout << "\nStatus     :" << right << setw(11) << s;
	cout << "\nWeight     :" << right << setw(11) << getWeight();
	// Finds and prints cost only if appropriate.
	if (s == "Accepted")
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nCost       :" << right << setw(11) << c;
	}
	else
	{
		cout << "\nCost       :" << right << setw(11) << "-";
	}
}