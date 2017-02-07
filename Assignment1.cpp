// a) Robert James Castleberry
// b) Complete 
// c) This program reads two integer values from the keyboard, performs mathematical operations on them, and displays the results.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// This is the main function of the program. It prompts for and then reads two inputs from the keyboard. Then it performs various operations and displays the results.

	int intOne, intTwo, sum, product, average, quotient, modulus;	// Declared variables for storing inputs and results.

	// Prompt for and read the integer inputs.
	cout << "Enter two integers: ";
	cin >> intOne >> intTwo;

	// Perform various mathematical operations on the inputs and store the results in declared variables.
	sum = intOne + intTwo;
	product = intOne * intTwo;
	average = sum / 2;
	quotient = intOne / intTwo;
	modulus = intOne % intTwo;

	// Display the results.
	cout << "Sum: " << sum << endl;
	cout << "Product: " << product << endl;
	cout << "Average: " << average << endl;
	cout << "Quotient: " << quotient << endl;
	cout << "Modulus: " << modulus << endl;
	return 0;
}




