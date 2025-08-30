#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1Won = 1, ComputerWon = 2, NoWinner = 3 };

struct stRoundResults
{
	enChoice Player1Choice;
	enChoice ComputerChoice;
	enWinner Winner;
	string RoundWinnerName = "";
};
struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string FinalWinner = "";
};

short ReadPositiveNumberInRange(string Message, const short From, const short To)
{
	short Number = 0;
	do
	{
		cout << Message;
		cin >> Number;

	} while (Number < From || Number > To);
	cout << "\n";

	return Number;
}

short RandomNumber(const short From, const short To)
{
	return rand() % (To - From + 1) + From;
}

enChoice ReadPlayer1Choice()
{
	return (enChoice)ReadPositiveNumberInRange("\n\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors -> ", 1, 3);
}

enChoice GetComputerChoice()
{
	return (enChoice)RandomNumber(1, 3);
}

enWinner CheckRoundWinner(enChoice Player1Choice, enChoice ComputerChoice)
{
	if (Player1Choice == ComputerChoice)
		return enWinner::NoWinner;

	switch (Player1Choice)
	{

	case enChoice::Stone:
		if (ComputerChoice == enChoice::Paper) return enWinner::ComputerWon;
		break;

	case enChoice::Paper:
		if (ComputerChoice == enChoice::Scissors) return enWinner::ComputerWon;
		break;

	case enChoice::Scissors:
		if (ComputerChoice == enChoice::Stone) return enWinner::ComputerWon;
	}

	return enWinner::Player1Won;
}


string GetChoiceName(enChoice Choice)
{
	string ArrChoices[3] = { "Stone", "Paper", "Scissors" };
	return ArrChoices[Choice - 1];
}

string GetWinnerName(enWinner Winner)
{
	string ArrWinner[3] = { "Player1", "Computer", "NoWinner" };
	return ArrWinner[Winner - 1];
}

enWinner CheckGameWinner(stGameResults GameResults)
{
	if (GameResults.ComputerWinTimes > GameResults.Player1WinTimes)
		return enWinner::ComputerWon;

	else if (GameResults.Player1WinTimes > GameResults.ComputerWinTimes)
		return enWinner::Player1Won;

	return enWinner::NoWinner;
}


string Tabs(short NumOfTabs)
{
	string t = "";
	for (short i = 1; i <= NumOfTabs; i++)
	{
		t += "\t";
	}

	return t;
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

void ResetScreen()
{
	system("color 0F");
	system("cls");
}

short HowManyRounds()
{
	return ReadPositiveNumberInRange("How Many Rounds 1 to 10? \n", 1, 10);
}

bool AskPlayAgain()
{
	char PlayAgain = 'Y';
	cout << Tabs(3) << "Do you want To Play Again? Y/N? ";
	cin >> PlayAgain;

	return (PlayAgain == 'Y' || PlayAgain == 'y');
}



void PrintRoundsResults(stRoundResults RoundResults, short NumOfRound)
{
	cout << "______________Round[" << NumOfRound << "]______________\n\n";
	cout << "Player1  Choice: " << GetChoiceName(RoundResults.Player1Choice) << "\n";
	cout << "Computer Choice: " << GetChoiceName(RoundResults.ComputerChoice) << "\n";
	cout << "Round Winner   : [" << RoundResults.RoundWinnerName << "]\n";
	cout << "____________________________________\n";

	ShowScreenColor(RoundResults.Winner);
}

stGameResults FillGameResults(short Player1WinTimes, short ComputerWinTimes, short DrawTimes, short Rounds)
{
	stGameResults GameResults;

	GameResults.GameRounds = Rounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = CheckGameWinner(GameResults);
	GameResults.FinalWinner = GetWinnerName(GameResults.GameWinner);

	return GameResults;
}

stGameResults PlayGame(short Rounds)
{
	stRoundResults RoundResults;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (int NumOfRound = 1; NumOfRound <= Rounds; NumOfRound++)
	{
		cout << "\nRounds [" << NumOfRound << "] begins: \n";
		RoundResults.Player1Choice = ReadPlayer1Choice();
		RoundResults.ComputerChoice = GetComputerChoice();
		RoundResults.Winner = CheckRoundWinner(RoundResults.Player1Choice, RoundResults.ComputerChoice);
		RoundResults.RoundWinnerName = GetWinnerName(RoundResults.Winner);

		switch (RoundResults.Winner)
		{
		case enWinner::Player1Won:
			Player1WinTimes++;
			break;

		case enWinner::ComputerWon:
			ComputerWinTimes++;
			break;

		case enWinner::NoWinner:
			DrawTimes++;
			break;
		}

		PrintRoundsResults(RoundResults, NumOfRound);
	}

	return FillGameResults(Player1WinTimes, ComputerWinTimes, DrawTimes, Rounds);
}

void ShowGameOverScreen()
{
	cout << Tabs(3) << "________________________________________________________________\n\n"
		<< Tabs(6) << "+++ Game Over +++\n"
		<< Tabs(3) << "________________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults, short Rounds)
{
	ShowGameOverScreen();

	cout << Tabs(3) << "________________________[ Game Results ]________________________\n\n";
	cout << Tabs(3) << "Game Rounds        : " << GameResults.GameRounds << "\n";
	cout << Tabs(3) << "Player1 Won times  : " << GameResults.Player1WinTimes << "\n";
	cout << Tabs(3) << "Computer Won times : " << GameResults.ComputerWinTimes << "\n";
	cout << Tabs(3) << "Draw times         : " << GameResults.DrawTimes << "\n";
	cout << Tabs(3) << "Final Winner       : " << GameResults.FinalWinner << "\n";
	cout << Tabs(3) << "________________________________________________________________\n\n\n\n";

	ShowScreenColor(GameResults.GameWinner);
}


void StartGame()
{
	bool PlayAgain = false;
	do
	{
		ResetScreen();

		short Rounds = HowManyRounds();
		stGameResults GameResults = PlayGame(Rounds);

		ShowFinalGameResults(GameResults, Rounds);

		PlayAgain = AskPlayAgain();

	} while (PlayAgain);
}



int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}