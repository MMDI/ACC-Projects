// a.) Robert James Castlebery
// b.) Incomplete - Program not functional. Incomplete or incorrect logic.
// critical member functions undefined or partially defined. Commenting missing.
// c.) This is the Scores class specification file.
#ifndef SCORES_H
#define SCORES_H
#include <string>
using namespace std;

struct StudentGrade
{
	string name;
	int score;

};

class Scores
{
	private:
		int numStudents;
		StudentGrade *studentScores;

	public:

		
		Scores();
		~Scores();

		void setScores(StudentGrade *, int);
		void sortScores();
		int getStudents();
		StudentGrade * getScores();
};
#endif