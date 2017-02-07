// a.) Robert James Castlebery
// b.) Incomplete - Program not functional. Incomplete or incorrect logic.
// critical member functions undefined or partially defined. Commenting missing.
// c.) This is the Scores class implementation file.
#include "Scores.h"

Scores::Scores()
{
	studentScores = NULL;
	numStudents = 0;

}

void Scores::setScores(StudentGrade *scores, int num)
{
	studentScores = scores;
	numStudents = num;
}

int Scores::getStudents()
{
	return numStudents;
}

StudentGrade * Scores::getScores()
{
	return studentScores;
}

void Scores::sortScores()
{
	StudentGrade *scores;
	int numStudents;
	bool swap;
	int temp;

	scores = getScores();
	numStudents = getStudents();

	do
	{
		swap = false;
		for (int k = 0; k < numStudents; k++)
		{
			if (*scores > *(scores + 1)
			{
				temp = *scores;

			}
		}

	}
}