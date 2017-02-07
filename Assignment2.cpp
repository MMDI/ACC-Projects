 // a.) Robert James Castleberry
// b.) Complete
// c.) This is a C++ program to help you balance your checkbook at the end of the month.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Establishes variables used throughout the main function.
	char choice;
	double balance,				 // Used to store the balance on the account.			
		   finalBalance = 0.0,	 // Used as the post test loop condition and in end of month processing.
		   serviceCharges = 0.0, // Used to keep a running total of service charges.
		   transactionAmount;	 // Used to store user transaction amounts.

	// Establishes the initial account balance.
	cout << "Checkbook Balancing Program\n\n";
	cout << "Enter the initial balance: ";
	cin  >> balance;

	// Processes user input and transactions using a repeating menu and switch statement.
	do
	{
		// Presents the main menu.
		cout << "\n\nCommands:\n";
		cout << "C - process a check.\n";
		cout << "D - process a deposit.\n";
		cout << "E - do end of month processing and exit the program.\n\n";
		cout << "Enter transaction type: ";
		
		// Receives user choice input.
		cin >> choice;

		// Creates branches depending on user choice input.
		switch (choice)
		{
		// Processes input checks.
		case 'c':
		case 'C':cout << "\nEnter transaction amount: ";
				 cin  >> transactionAmount;
				 // Validates transaction amount input, processes transaction, and prints results.
				 if (transactionAmount > 0)
				 {
					 cout << fixed << showpoint << setprecision(2);
					 cout << "\nProcessing check for $" << transactionAmount;
					 balance -= transactionAmount;
					 serviceCharges += .25;
					 cout << "\nBalance: $" << balance;
					 cout << "\nTotal service charges: $" << serviceCharges;
				 }
				 // Prints error message if transaction amount input is invalid.
				 else
				 {
					 cout << "The transaction amount must be larger than zero";
				 }
				 break;
		// Proccesses input deposits.
		case 'd':
		case 'D':cout << "\nEnter transaction amount: ";
				 cin  >> transactionAmount;
				 // Validates transaction amount input, processes transaction, and prints results.
				 if (transactionAmount > 0)
				 {
					 cout << fixed << showpoint << setprecision(2);
					 cout << "\nProcessing deposit for $" << transactionAmount;
					 balance += transactionAmount;
					 cout << "\nBalance: $" << balance;
					 cout << "\nTotal service charges: $" << serviceCharges;
				 }
				 // Prints error message if transaction amount input is invalid.
				 else
				 {
					 cout << "The transaction amount must be larger than zero";
				 }
				 break;
		// Processes end of month.
		case 'e':
		case 'E':cout << fixed << showpoint << setprecision(2);
				 cout << "\nProcessing end of month";
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
