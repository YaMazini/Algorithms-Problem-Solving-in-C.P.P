#include <iostream>
#include <cstdlib> 
using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1Won = 1, ComputerWon = 2, NoWinner = 3 };

struct stRoundResults
{
	string Player1Choice = "";
	string ComputerChoice = "";
	string RoundWinner = "";
};
struct stGameResults
{
	short Player1Wins = 0;
	short ComputerWins = 0;
	short DrawTimes = 0;
	string FinalWinner;
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

short RandomNumber(const short From, const short To)
{
	return rand() % (To - From + 1) + From;
}


enChoice GetPlayer1_Choice(stRoundResults& Roundresults)
{
	short Choice = ReadPositiveNumberInRange("\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors -> ", 1, 3);

	switch (Choice)
	{
	case enChoice::Stone:
		Roundresults.Player1Choice = "Stone";
		return enChoice::Stone;

	case enChoice::Paper:
		Roundresults.Player1Choice = "Paper";
		return enChoice::Paper;

	case enChoice::Scissors:
		Roundresults.Player1Choice = "Scissors";
		return enChoice::Scissors;
	}
}

enChoice GetComputer_Choice(stRoundResults& Roundresults)
{
	short Choice = RandomNumber(1, 3);

	switch (Choice)
	{
	case enChoice::Stone:
		Roundresults.ComputerChoice = "Stone";
		return enChoice::Stone;

	case enChoice::Paper:
		Roundresults.ComputerChoice = "Paper";
		return enChoice::Paper;

	case enChoice::Scissors:
		Roundresults.ComputerChoice = "Scissors";
		return enChoice::Scissors;
	}
}

enWinner CheckRoundWinner(enChoice Player1_Choice, enChoice Computer_Choice)
{
	//Cases: If Computer Won
	if ((Player1_Choice == enChoice::Stone && Computer_Choice == enChoice::Paper) ||
		(Player1_Choice == enChoice::Paper && Computer_Choice == enChoice::Scissors) ||
		(Player1_Choice == enChoice::Scissors && Computer_Choice == enChoice::Stone))

		return enWinner::ComputerWon;


	//Cases: If Player1 Won
	else if ((Player1_Choice == enChoice::Paper && Computer_Choice == enChoice::Stone) ||
		(Player1_Choice == enChoice::Scissors && Computer_Choice == enChoice::Paper) ||
		(Player1_Choice == enChoice::Stone && Computer_Choice == enChoice::Scissors))

		return enWinner::Player1Won;


	//Cases: If No Winner (Draw)
	else

		return enWinner::NoWinner;

}

void GetRoundResults(stGameResults& GameResults, stRoundResults& RoundResults, enWinner RoundWinner)
{
	switch (RoundWinner)
	{
	case enWinner::ComputerWon:
		RoundResults.RoundWinner = "Computer";
		GameResults.ComputerWins += 1;
		break;

	case enWinner::Player1Won:
		RoundResults.RoundWinner = "Player1";
		GameResults.Player1Wins += 1;
		break;

	case enWinner::NoWinner:
		RoundResults.RoundWinner = "NoWinner";
		GameResults.DrawTimes += 1;
		break;
	}
}


enWinner CheckGameWinner(stGameResults& GameResults)
{
	if (GameResults.ComputerWins > GameResults.Player1Wins)
		return enWinner::ComputerWon;

	else if (GameResults.Player1Wins > GameResults.ComputerWins)
		return enWinner::Player1Won;

	else
		return enWinner::NoWinner;
}

void GetGameResults(stGameResults& GameResults)
{
	switch (CheckGameWinner(GameResults))
	{
	case enWinner::ComputerWon:
		GameResults.FinalWinner = "Computer";
		break;

	case enWinner::Player1Won:
		GameResults.FinalWinner = "Player1";
		break;

	case enWinner::NoWinner:
		GameResults.FinalWinner = "NoWinner";
		break;
	}
}


short ReadHowManyRounds()
{
	return ReadPositiveNumberInRange("\nHow Many Rounds 1 to 10: ", 1, 10);
}

string Tabs()
{
	return "\t\t\t";
}

bool WantPlayAgain()
{
	char Choice;
	cout << "\n" << Tabs() << "Do you want to play again? Y/N? ";
	cin >> Choice;

	return (Choice == 'Y' || Choice == 'y');
}

void ResetScreen()
{
	system("cls");
}

void ShowScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::ComputerWon:
		system("color 4E");
		cout << "\a";
		break;

	case enWinner::Player1Won:
		system("color 2A");
		break;

	case enWinner::NoWinner:
		system("color 6E");
		break;
	}
}


void ShowRoundResults(stGameResults& GameResults, stRoundResults& RoundResults, short NumberOfRounds)
{
	enChoice Player1_Choice = GetPlayer1_Choice(RoundResults);
	enChoice Computer_Choice = GetComputer_Choice(RoundResults);
	enWinner RoundWinner = CheckRoundWinner(Player1_Choice, Computer_Choice);

	GetRoundResults(GameResults, RoundResults, RoundWinner);

	cout << "\n______________Round[" << NumberOfRounds << "]______________\n";
	cout << "\nPlayer1  Choice: " << RoundResults.Player1Choice;
	cout << "\nComputer Choice: " << RoundResults.ComputerChoice;
	cout << "\nRound Winner   : " << RoundResults.RoundWinner;
	cout << "\n____________________________________\n";

	ShowScreenColor(RoundWinner);
}

void ShowGameOverScreen()
{
	cout << Tabs() << "_______________________________________________________________\n\n"
		<< Tabs() << "\t\t\t+++ Game Over +++\n"
		<< Tabs() << "_______________________________________________________________\n";
}

void ShowFinalGameResults(stGameResults& GameResults, stRoundResults& RoundResults, short NumOfRounds)
{
	enWinner GameWinner = CheckGameWinner(GameResults);
	GetGameResults(GameResults);

	ShowGameOverScreen();

	cout << "\n\n\n" << Tabs() << "________________________[ Game Results ]_______________________\n";

	cout << "\n" << Tabs() << "Game Rounds        : " << NumOfRounds;
	cout << "\n" << Tabs() << "Player1 Won times  : " << GameResults.Player1Wins;
	cout << "\n" << Tabs() << "Computer Won times : " << GameResults.ComputerWins;
	cout << "\n" << Tabs() << "Draw times         : " << GameResults.DrawTimes;
	cout << "\n" << Tabs() << "Final Winner       : " << GameResults.FinalWinner;

	cout << "\n" << Tabs() << "_______________________________________________________________";

	ShowScreenColor(GameWinner);
}


void StartGame()
{
	bool PlayMore = 0;
	do
	{
		ResetScreen();

		stGameResults GameResults;
		stRoundResults RoundResults;
		short Rounds = ReadHowManyRounds();

		for (int i = 1; i <= Rounds; i++)
		{
			cout << "\n\nRound [" << i << "] begins: \n";
			ShowRoundResults(GameResults, RoundResults, i);
		}

		ShowFinalGameResults(GameResults, RoundResults, Rounds);


		PlayMore = WantPlayAgain();

	} while (PlayMore);
}




int main()
{
	srand((unsigned)time(NULL));


	StartGame();


	return 0;
}
