// a.) Robert James Castlebery
// b.) Incomplete - Program not functional. Incomplete or incorrect logic.
// critical member functions undefined or partially defined. Commenting missing.
// c.) This program processes test scores for a class.
#include <string>
#include <iostream>
#include <iomanip>
#include "Scores.h"
using namespace std;

int main()
{
	int students;
	StudentGrade *scrs;
	Scores testScores;

	cout << "Please enter the number of students: ";
	cin >> students;

	scrs = new StudentGrade[students];

	for (int k = 0; k < students; k++)
	{
		cout << "\n\nPlease enter the name of student " << (k + 1) << ": ";
		cin >> scrs[k].name;
		cout << "\nPlease enter the score of student " << (k + 1) << ": ";
		cin >> scrs[k].score;
	}

	testScores.setScores(scrs, students);
	testScores.sortScores();

}