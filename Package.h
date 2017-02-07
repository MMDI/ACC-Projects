// a.) Robert James Castleberry
// b.) Complete
// c.) This is the Package class specification file
#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

// Package class declaration.
class Package
{
	private:
		int weight,	// Stores weight input.
			side1,	// Stores dimension 1 input.
			side2,	// Stores dimension 2 input.
			side3;	// Stores dimension 3 input.
				
	public:
		Package();	// Constructor.
		void setPack(int, int, int, int); // Prompts for and receives input for package specifications.
		double getCost();	// Searches for and returns the cost of shipping a package.
		int getWeight();	// Returns package weight.
		void printTrans(int, string, double);	// Prints the details of a transaction.
};
#endif