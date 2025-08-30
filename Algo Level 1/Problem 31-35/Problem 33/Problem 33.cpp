
#include <iostream>
using namespace std;

enum enGrades { A = 1, B = 2, C = 3, D = 4, E = 5, F = 6};


int ReadGradeFromTo(int From, int To)
{
	int Grade;
	do
	{
		cout << "Please Enter Your Grade: ", cin >> Grade;

	} while (Grade < From || Grade > To);

	return Grade;
}

enGrades CheckGrade(int Grade)
{	
	if (Grade >= 90 && Grade <= 100)
		return enGrades::A;

	else if (Grade >= 80 && Grade <= 89)
		return enGrades::B;

	else if (Grade >= 70 && Grade <= 79)
		return enGrades::C;

	else if (Grade >= 60 && Grade <= 69)
		return enGrades::D;

	else if (Grade >= 50 && Grade <= 59)
		return enGrades::E;

	else
		return enGrades::F;
}

char GetGradeLetter(int Grade)
{
	char LetterGrade;
	if (CheckGrade(Grade) == enGrades::A)
		return LetterGrade = 'A';

	else if (CheckGrade(Grade) == enGrades::B)
		return LetterGrade = 'B';

	else if (CheckGrade(Grade) == enGrades::C)
		return LetterGrade = 'C';

	else if (CheckGrade(Grade) == enGrades::D)
		return LetterGrade = 'D';

	else if (CheckGrade(Grade) == enGrades::E)
		return LetterGrade = 'E';

	else if (CheckGrade(Grade) == enGrades::F)
		return LetterGrade = 'F';

}

void PrintResult(int Grade)
{
	cout << " \nThe Letter Grade of " << Grade << " is: " << GetGradeLetter(Grade) << endl;
}



int main()
{

	PrintResult(ReadGradeFromTo(0, 100));

	return 0;
}      //a lot of complexity hhhh 