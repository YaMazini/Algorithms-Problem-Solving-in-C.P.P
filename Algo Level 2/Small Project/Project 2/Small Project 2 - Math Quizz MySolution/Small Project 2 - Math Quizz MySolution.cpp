#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Addition = 1, Subtruct = 2, Multiplication = 3, Division = 4, MixOperation = 5 };

struct stQuestionInfo
{
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int Number1 = 0;
	int Number2 = 0;
	string OperationSymbol;
	int UserAnswer = 0;
	int OperationResult = 0;
};
struct stQuizzResults
{
	short Questions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short RightAnswers = 0;
	short WrongAnswers = 0;
	string FinalResult = "";
};


short ReadPositiveNumberInRange(string Message, const short From, const short To)
{
	short Number = 0;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

int RandomNumber(const short From, const short To)
{
	return rand() % (To - From + 1) + From;
}


enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel;
	QuestionLevel = ReadPositiveNumberInRange("\nEnter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix: ", 1, 4);

	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
	short OperationType;
	OperationType = ReadPositiveNumberInRange("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5]Mix: ", 1, 5);
	cout << "\n";

	return (enOperationType)OperationType;
}

bool IsMixLevel(enQuestionLevel QuestionLevel)
{
	return (QuestionLevel == enQuestionLevel::MixLevel);
}

bool IsMixOperationType(enOperationType OperationType)
{
	return (OperationType == enOperationType::MixOperation);
}

enQuestionLevel RandomQuestionLevel()
{
	return (enQuestionLevel)RandomNumber(1, 3);
}

enOperationType RandomOperationType()
{
	return (enOperationType)RandomNumber(1, 4);
}


string QuestionLevelToString(enQuestionLevel QuestionLevel)
{
	string ArrQuestionLevel[5] = { "Easy", "Med", "Hard", "Mix" };
	return ArrQuestionLevel[QuestionLevel - 1];
}

string OperationTypeToString(enOperationType OperationType)
{
	string ArrOperationType[5] = { "+", "-", "*", "/" , "Mix" };
	return ArrOperationType[OperationType - 1];
}


int GenerateRandomNum_ByQuestionLevel(enQuestionLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		return RandomNumber(1, 10);

	case enQuestionLevel::Med:
		return RandomNumber(10, 50);

	case enQuestionLevel::Hard:
		return RandomNumber(10, 100);
	}

}

int CalculateOperationResult(enOperationType OperationType, int Number1, int Number2)
{
	switch (OperationType)
	{
	case enOperationType::Addition:
		return Number1 + Number2;

	case enOperationType::Subtruct:
		return Number1 - Number2;

	case enOperationType::Multiplication:
		return Number1 * Number2;

	case enOperationType::Division:
		return Number1 / Number2;
	}
}


bool IsCorrectAnswer(int UserAnswer, int OperationResult)
{
	return (UserAnswer == OperationResult);
}

string CheckCorrectAnswer(int UserAnswer, int OperationResult)
{
	if (IsCorrectAnswer(UserAnswer, OperationResult))
		return "Right Answer :)\n";

	return "Wrong Answer :( \nThe Right Answer is: " + to_string(OperationResult) + "\n";
}

bool IsPass(short RightAnswers, short WrongAnswers)
{
	return (RightAnswers > WrongAnswers);
}

string CheckIfPass(short RightAnswers, short WrongAnswers)
{
	return (IsPass(RightAnswers, WrongAnswers)) ? "Pass : )" : "Fail :(";
}


short HowManyQuestions()
{
	return ReadPositiveNumberInRange("How Many Questions do you want to answer? ", 1, 100);
}

void ShowScreenColor(bool Checking)
{
	if (Checking)
	{
		system("color 2A");
	}

	else
	{
		system("color 4E");
		cout << "\a";
	}
}

void ResetScreen()
{
	system("color 0F");
	system("cls");
}

char AskToPlayAgain()
{
	char PlayAgain = 'Y';
	cout << "Do You want to play again? Y/N?";
	cin >> PlayAgain;

	return PlayAgain;
}


void PrintQuestionResult(stQuestionInfo& QuestionInfo, short Questions, short NumOfQuestion)
{
	cout << "Question [" << NumOfQuestion << "/" << Questions << "]\n\n";
	cout << QuestionInfo.Number1 << "\n";
	cout << QuestionInfo.Number2 << " ";
	cout << QuestionInfo.OperationSymbol << "\n";
	cout << "__________\n";
	cin >> QuestionInfo.UserAnswer;
	cout << CheckCorrectAnswer(QuestionInfo.UserAnswer, QuestionInfo.OperationResult) << "\n";

	ShowScreenColor(IsCorrectAnswer(QuestionInfo.UserAnswer, QuestionInfo.OperationResult));
}

stQuizzResults FillQuizzResults(enQuestionLevel QuestionLevel, enOperationType OperationType, short RightAnswers, short WrongAnswers, short NumberOfQuestions)
{
	stQuizzResults QuizzResults;

	QuizzResults.Questions = NumberOfQuestions;
	QuizzResults.QuestionLevel = QuestionLevel;
	QuizzResults.OperationType = OperationType;

	QuizzResults.RightAnswers = RightAnswers;
	QuizzResults.WrongAnswers = WrongAnswers;
	QuizzResults.FinalResult = CheckIfPass(QuizzResults.RightAnswers, QuizzResults.WrongAnswers);

	return QuizzResults;
}

stQuizzResults Quizz(short Questions)
{
	stQuestionInfo QuestionInfo;
	short RightAnswers = 0, WrongAnswers = 0;
	enQuestionLevel QuestionLevel = ReadQuestionLevel();
	enOperationType OperationType = ReadOperationType();

	for (int NumOfQuestion = 1; NumOfQuestion <= Questions; NumOfQuestion++)
	{
		if (IsMixLevel(QuestionLevel))
		{
			QuestionInfo.QuestionLevel = RandomQuestionLevel();
		}

		else
			QuestionInfo.QuestionLevel = QuestionLevel;

		if (IsMixOperationType(OperationType))
		{
			QuestionInfo.OperationType = RandomOperationType();
		}

		else
			QuestionInfo.OperationType = OperationType;

		QuestionInfo.Number1 = GenerateRandomNum_ByQuestionLevel(QuestionInfo.QuestionLevel);
		QuestionInfo.Number2 = GenerateRandomNum_ByQuestionLevel(QuestionInfo.QuestionLevel);
		QuestionInfo.OperationSymbol = OperationTypeToString(QuestionInfo.OperationType);
		QuestionInfo.OperationResult = CalculateOperationResult(QuestionInfo.OperationType, QuestionInfo.Number1, QuestionInfo.Number2);

		PrintQuestionResult(QuestionInfo, Questions, NumOfQuestion);

		if (IsCorrectAnswer(QuestionInfo.UserAnswer, QuestionInfo.OperationResult))
			RightAnswers++;

		else
			WrongAnswers++;
	}

	return FillQuizzResults(QuestionInfo.QuestionLevel, OperationType, RightAnswers, WrongAnswers, Questions);
}

void ShowFinalResultScreen(string FinalResult)
{
	cout << "\n______________________________\n\n";
	cout << " Final Results is " << FinalResult << "\n";
	cout << "______________________________\n\n";
}

void ShowQuizzResults(stQuizzResults QuizzResults)
{
	cout << "Number Of Questions     :" << QuizzResults.Questions << "\n";
	cout << "Questions Level         :" << QuestionLevelToString(QuizzResults.QuestionLevel) << "\n";
	cout << "Operation Type          :" << OperationTypeToString(QuizzResults.OperationType) << "\n";
	cout << "Number of Right Answers :" << QuizzResults.RightAnswers << "\n";
	cout << "Number of WrongAnswers  :" << QuizzResults.WrongAnswers << "\n";
	cout << "______________________________\n\n";

	ShowScreenColor(IsPass(QuizzResults.RightAnswers, QuizzResults.WrongAnswers));
}


void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		short Questions = HowManyQuestions();

		stQuizzResults QuizzResults = Quizz(Questions);

		ShowFinalResultScreen(QuizzResults.FinalResult);
		ShowQuizzResults(QuizzResults);


		PlayAgain = AskToPlayAgain();

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}




int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}