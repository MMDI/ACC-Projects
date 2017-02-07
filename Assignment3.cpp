// a.) Robert James Castleberry
// b.) Complete
// c.) This is a C++ program to help you balance your checkbook at the end of the month.
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void check(double transactionAmount, double &balance, double &serviceCharges, bool &lowCharged);
void deposit(double transactionAmount, double &balance, double serviceCharges);

// Establishes global constants.
const double checkFee = 0.25, // Used to store the check service charge fee amount.
	lowFee = 5.0,			  // Used to store the low balance service charge fee amount.
	overFee = 25.0;           // Used to store the overdraft service charge fee amount.

int main()
{
	// Establishes variables used throughout the main function.
	char choice;				// Used to store the user input menu choice.
	double balance,				// Used to store the balance on the account.			
		finalBalance = 0.0,	    // Used as the post test loop condition and in end of month processing.
		serviceCharges = 0.0,   // Used to keep a running total of service charges.
		transactionAmount;		// Used to store user transaction amounts.
	bool lowCharged = false;	// Used to track whether the low balance fee has been charged.
	
	// Establishes the initial account balance.
	cout << "Checkbook Balancing Program\n\n";
	cout << "Enter the initial balance: ";
	cin >> balance;

	// Processes user input and transactions using a repeating menu and switch statement.
	do
	{
		// Presents the main menu.
		cout << "\n\nCommands:\n";
		cout << "C - process a check.\n";
		cout << "D - process a deposit.\n";
		cout << "E - do end of month processing and exit the program.\n\n";
		cout << "Enter transaction type and amount (zero amount for E): ";

		// Receives user choice and transaction amount input.
		cin >> choice >> transactionAmount;

		// Creates branches depending on user choice input.
		switch (choice)
		{
			// Processes input checks.
		case 'c':
		case 'C': check(transactionAmount, balance, serviceCharges, lowCharged);
			break;
			// Proccesses input deposits.
		case 'd':
		case 'D':deposit(transactionAmount, balance, serviceCharges);
			break;
			// Processes end of month.
		case 'e':
		case 'E':cout << fixed << showpoint << setprecision(2);
			cout << "Processing end of month";
			// Deducts service charges from account balance.
			balance -= serviceCharges;
			// Changes the value of the post test loop condition and prints the final balance.
			finalBalance += balance;
			cout << "\nFinal Balance: $" << finalBalance;

			// Creates a pause so the final balance can be viewed.
			cin.ignore();
			cout << "\nPress [Enter] to exit the program: ";
			cin.get();
			break;
			// Prints an error message if the user choice input is invalid.
		default: cout << "\nThat is an invalid choice.";
		}
	} while (finalBalance == 0.0);

	return 0;
}

// Function definitions for check and deposit processing.
void check(double transactionAmount, double &balance, double &serviceCharges, bool &lowCharged)
{
	// Validates input before processing.
	if (transactionAmount > 0)
	{
		// Processes check and prints results.
		cout << fixed << showpoint << setprecision(2);
		cout << "Processing check for $" << transactionAmount;
		balance -= transactionAmount;
		serviceCharges += checkFee;
		// Charges low balance fee when appropriate.
		if (balance < 800 && lowCharged == false)
		{
			balance -= lowFee;
			serviceCharges += lowFee;
			lowCharged = true;
		}
		// Charges overdraft fee when appropriate.
		if (balance < 0)
		{
			balance -= overFee;
			serviceCharges += overFee;
		}
		cout << "\nBalance: $" << balance;
		cout << "\nTotal service charges: $" << serviceCharges;
	}
	// Prints error message if transaction amount input is invalid.
	else
	{
		cout << "The transaction amount must be larger than zero";
	}
}

void deposit(double transactionAmount, double &balance, double serviceCharges)
{
	// Validates input before processing.
	if (transactionAmount > 0)
	{
		// Processes deposit and prints results.
		cout << fixed << showpoint << setprecision(2);
		cout << "Processing deposit for $" << transactionAmount;
		balance += transactionAmount;
		cout << "\nBalance: $" << balance;
		cout << "\nTotal service charges: $" << serviceCharges;
	}
	// Prints error message if transaction amount input is invalid.
	else
	{
		cout << "The transaction amount must be larger than zero";
	}
}