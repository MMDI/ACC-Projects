// a.) Robert James Castleberry
// b.) Complete
// c.) This program processes transactions for Lone Star Package service.
#include "Package.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Main program function. Performs I/O for transactions.
int main()
{	
	Package pack1;	// Instantiates a Package object.
	int weightTemp = 0;	// For storing weight input.
	int side1Temp = 0;	// For storing dimensional input.
	int side2Temp = 0;	// For storing dimensional input.
	int side3Temp = 0;	// For storing dimensional input.
	int largest;	// For storing the largest dimension.
	int transNum = 0;	// Tracks how many transactions have been processed.
	int totalAccepted = 0;	// Running total of accepted packages.
	int totalRejected = 0;	// Running total of rejected packages.

	// Instructs user how to enter input.
	cout << "For each transaction, enter a package weight and 3 dimensions.";
	cout << "\nEnter -1 to quit.";

	// Transaction processing loop.
	while (weightTemp != -1)
	{	
		double cst,	// Stores returned cost of shipment.
			   girth;	// Stores package girth.
		string status;	// Stores a string for printing "accepted" or "rejected".

		// Takes user input and validates it.
		cout << endl << "\n\nEnter package weight and 3 dimensions: ";
		cin >> weightTemp;
		// Breaks loop if user requests.
		if (weightTemp == -1)
		{
			break;
		}
		if (weightTemp > 0)
		{
			cin >> side1Temp;
			
			if (side1Temp > 0)
			{
				cin >> side2Temp;

				if (side2Temp > 0)
				{
					cin >> side3Temp;

					if (side3Temp > 0)
					{
						// Increments transaction number.
						transNum++;
						// Sets initial value for largest.
						largest = side1Temp;
						// Compares dimensions to find largest.
						if (side2Temp > largest)
						{
							largest = side2Temp;
						}
						
						if (side3Temp > largest)
						{
							largest = side3Temp;
						}
						// Calculates girth.
						girth = 2 * (side1Temp + side2Temp + side3Temp - largest);
						// Determines statues of transaction.
						if (weightTemp > 50)
						{
							status = "Rejected";
							totalRejected++;
						}
						else if (side1Temp > 3)
						{
							status = "Rejected";
							totalRejected++;
						}
						else if (side2Temp > 3)
						{
							status = "Rejected";
							totalRejected++;
						}
						else if (side3Temp > 3)
						{
							status = "Rejected";
							totalRejected++;
						}
						else if (girth > 5)
						{
							status = "Rejected";
							totalRejected++;
						}
						else
						{
							status = "Accepted";
							totalAccepted++;
						}
						// Sets pack data and prints.
						pack1.setPack(weightTemp, side1Temp, side2Temp, side3Temp);
						cst = pack1.getCost();
						pack1.printTrans(transNum, status, cst);
					}
					// Prints error message and skips transaction.
					else
					{
						cout << "\nError! Invalid entry for dimension 3. Value must be [1, 3].";
						cout << "\nTransaction skipped.";
					}
				}
				// Prints error message and skips transaction.
				else
				{
					cout << "\nError! Invalid entry for dimension 2. Value must be [1, 3].";
					cout << "\nTransaction skipped.";
				}
			}
			// Prints error message and skips transaction.
			else
			{
				cout << "\nError! Invalid entry for dimension 1. Value must be [1, 3].";
				cout << "\nTransaction skipped.";
			}
		}
		// Prints error message and skips transaction.
		else
		{
			cout << "\nError! Invalid entry for weight. Value must be [1, 50].";
			cout << "\nTransaction skipped.";
		}
	}
	// Prints running totals
	cout << "\nNumber of accepted packages: " << totalAccepted;
	cout << "\nNumber of rejected packages: " << totalRejected;

	// Creates a pause so the output can be viewed.
	cin.ignore();
	cout << "\n\nPress [Enter] to exit the program: ";
	cin.get();

	return 0; // End of program.
}