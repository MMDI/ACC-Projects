// a.) Robert James Castlebery
// b.) Complete
// c.) This is a payroll program for Armadillo Automotive Group.
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Defines Employee Master info structure.
struct EmployeeMaster
{
	int empNumber;	// Stores employee ID number.
	string name;	// Stores employee name.	
	double payRate;	// Stores employee pay rate.
	int empType;	// Stores employee type.

	//Constructor
	EmployeeMaster(int en = 0, string n = "", double pr = 0.0, int et = 0)
	{
		empNumber = en;
		name = n;
		payRate = pr;
		empType = et;
	}
};

bool validateEmp(int, double, int);	// Validates structure data. This seemed easier than several loops.

// The main program function for all input, output, and payroll processing.
int main()
{
	const double OVERTIME_RATE = 1.5;	// Flat overtime rate.
	const double TAX_RATE = .15;	// Flat tax rate.
	const int NUM_EMPS = 4;	// Number of employees.
	
	EmployeeMaster employees[NUM_EMPS+1];	// Array of structures.

	double hours[NUM_EMPS+1]; // Array of hours worked.
	double grossPay[NUM_EMPS+1];	// Array of gross pay amounts.
	double netPay[NUM_EMPS+1];	// Array of net pay amounts.
	double taxes[NUM_EMPS+1];	// Array of tax amounts.

	double totalGross = 0.0;	// Gross pay running total.
	double totalNet = 0.0;	// Net pay running total.
	int index;	// Indexing variable.

	
	// Requests and receives Employee Master info.
	for (index = 1; index <= NUM_EMPS; index++)
	{
		// Asks for and receives initial input.
		cout << "\nEnter information for employee" << index;
		cout << "\nEmployee number: ";
		cin  >> employees[index].empNumber;
		cout << "Employee name: ";
		cin.ignore();
		getline(cin, employees[index].name);
		cout << "Pay rate: ";
		cin  >> employees[index].payRate;
		cout << "Type: ";
		cin  >> employees[index].empType;

		// Asks user for new input until validated.
		while (!validateEmp(employees[index].empNumber, employees[index].payRate, employees[index].empType))
		{
			// Alerts user when input is invalid.
			cout << "\nInvalid input!";
			cout << "\nEmployee number should be a positive number greater than 0";
			cout << "\nEmployee type should be 0 or 1";
			// Asks for re-entry of input.
			cout << "\n\nPlease re-enter information for employee" << index;
			cout << "\nEmployee number: ";
			cin  >> employees[index].empNumber;
			cout << "Employee name: ";
			cin.ignore();
			getline(cin, employees[index].name);
			cout << "Pay rate: ";
			cin  >> employees[index].payRate;
			cout << "Type: ";
			cin  >> employees[index].empType;
		}
	}

	
	// Prints payroll entry instructions for user.
	cout << "\nEnter timecard information for each employee:\n";

	// Receives and processes payroll information.
	for (index = 1; index <= NUM_EMPS; index++)
	{
		// Receives input for employee hours.
		cout << "Hours worked for " << employees[index].name << ": ";
		cin >> hours[index];

		// Asks for hours input re-entry until validated.
		while (hours[index] < 0)
		{
			cout << "\nHours worked must be a value larger than 0.";
			cout << "Please re-enter hours worked for " << employees[index].name << ": ";
			cin >> hours[index];
		}

		// Calculates wages and taxes.
		if (employees[index].empType == 0 && hours[index] <= 40)
		{
			grossPay[index] = employees[index].payRate * hours[index];
			taxes[index] = grossPay[index] * TAX_RATE;
			netPay[index] = grossPay[index] - taxes[index];
		}
		else if (employees[index].empType == 0 && hours[index] > 40)
		{
			grossPay[index] = (employees[index].payRate * 40) + ((hours[index] - 40)*(employees[index].payRate * OVERTIME_RATE));
			taxes[index] = grossPay[index] * TAX_RATE;
			netPay[index] = grossPay[index] - taxes[index];
		}
		else // Management.
		{
			grossPay[index] = employees[index].payRate * hours[index];
			taxes[index] = grossPay[index] * TAX_RATE;
			netPay[index] = grossPay[index] - taxes[index];
		}

		// Keeps a running total.
		totalGross += grossPay[index];
		totalNet += netPay[index];

	}

	// Creates a pause until the user is finished viewing this portion of the program
	// and ready to proceed with payroll processing.
	cin.ignore();
	cout << "\n\nPress [Enter] to process payroll report: ";
	cin.get();

	// Mimics clearing the screeing without using scary system() functions
	// so the input prompts are not mixed in with the report.
	cout << string(50, '\n');

	// Prints title and column names.
	cout << "Payroll Report\n\n";
	cout << "ID   Name                Gross Pay      Tax  Net Pay\n";

	// Loop for printing payroll.
	for (index = 1; index <= NUM_EMPS; index++)
	{
		// Formats float output.
		cout << fixed << showpoint << setprecision(2);
		
		// Prints the payroll report.
		cout << left  << setw(5)  << employees[index].empNumber
			 << left  << setw(20) << employees[index].name
			 << right << setw(9)  << grossPay[index]
			 << right << setw(9)  << taxes[index]
			 << right << setw(9)  << netPay[index] << endl;
	}

	// Prints running totals.
	cout << fixed << showpoint << setprecision(2);
	cout << "\nTotal Gross Pay $" << right << setw(8) << totalGross;
	cout << "\nTotal Net Pay   $" << right << setw(8) << totalNet;

	// Creates a pause until the user is finished viewing the report.
	cin.ignore();
	cout << "\nPress [Enter] to end the program: ";
	cin.get();
	
	return 0; // End of program.
}

// Definition of a function that validates Employee Master info.
bool validateEmp(int x, double y, int z)
{
	bool validData = true;

	if (x <= 0 || y <= 0)
	{
		validData = false;
	}
	else if (z != 0 && z != 1)
	{
		validData = false;
	}
	else
	{
		validData = true;
	}
	return validData;
}