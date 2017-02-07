//Prototype
void check(double transactionAmount, double &balance, double &serviceCharges, bool &lowCharged);

//Definition
void check(double transactionAmount, double &balance, double &serviceCharges, bool &lowCharged)
{
	if (transactionAmount > 0)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nProcessing check for $" << transactionAmount;
		balance -= transactionAmount;
		serviceCharges += checkFee;
		if (balance < 800 && lowCharged == false)
		{
			balance -= lowFee;
			serviceCharges += lowFee;
			lowCharged = true;
		}
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

//Prototype
void deposit(double transactionAmount, double &balance, double serviceCharges);

//Definition
void deposit(double transactionAmount, double &balance, double serviceCharges)
{
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
}
