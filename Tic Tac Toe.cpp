#include <iostream>

using namespace std;

const int ROWS = 3, COLUMNS = 3; // Initialize rows and columns in array;

int** createBoard() //Creating array board;
{
	int** board = new int* [ROWS];

	int count = 1;

	for (int i = 0; i < ROWS; i++)
	{
		board[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j] = count; //sample set value;
			count++;
		}
	}
	return board;
}

void printBoard(int** board) // Printing board;
{
	system("cls"); // system ("clear");

	cout << "\t\t\t\t\t\t-------------" << endl;

	for (int i = 0; i < ROWS; i++) 
	{
		cout << "\t\t\t\t\t\t| ";

		for (int j = 0; j < COLUMNS; j++) 
		{
			if (board[i][j] == 111)
			{
				cout << "o" << " | ";
			}
			
			else if (board[i][j] == 120)
			{
				cout << "x" << " | ";
			}
			
			else
			{
				cout << board[i][j] << " | ";
			}
		}
		cout << endl;
		cout << "\t\t\t\t\t\t-------------" << endl;
	}
}

char* choiseSymbol() // First player must choose a symbol 'x' or 'o';
{
	char symbolOfFirstPlayer;
	char symbolOfSecondPlayer;

	cout << "First player choose the symbol x or o: " << endl;
	cin >> symbolOfFirstPlayer;

	if (isalpha(symbolOfFirstPlayer)) 
	{
		symbolOfFirstPlayer = tolower(symbolOfFirstPlayer);
	}

	while (symbolOfFirstPlayer != 'x' && symbolOfFirstPlayer != 'o')
	{
		cout << "You enter uncorrect symbol, choose x or o: " << endl;
		cin >> symbolOfFirstPlayer;
	}

	switch (symbolOfFirstPlayer)
	{
	case 'x':
		symbolOfSecondPlayer = 'o';
		break;

	case 'o':
		symbolOfSecondPlayer = 'x';
		break;
	}
	static char result[] = { symbolOfFirstPlayer, symbolOfSecondPlayer };
	return result;
}

bool fillBoard(int** board, char symbol) // Fill board;
{
	int number;

	cin >> number;
	
	while (number < 1 || number > 9)
	{
		cout << "You have chosen the uncorrect number. Try again please. Number shuld be 1-9: " << endl;
		cin >> number;
	}

	bool found = false;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (board[i][j] == number)
			{
				board[i][j] = symbol;
				cout << board[i][j] << endl;

				found = true;
				break; // Break the inner loop;
			}
		}
		if (found) 
		{
			break; // Break the outer loop;
		}
	}
	return found;
}

bool checkWinners(int** board) // Check winners, if player is winner, return true;
{
	for (int i = 0; i < ROWS; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return true;
		}
	}

	for (int j = 0; j < COLUMNS; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
		{
			return true;
		}
	}
	
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return true;
	}
	
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return true;
	}
	return false;
}

int main(int argc, char** argv) 
{
	int choice;
	int count = 0;

	cout << "\t\t\t\t\tWelcome to tic tac toe!" << endl;
	cout << "\t\t\t\t\tAre you ready to play?" << endl;
	cout << "\t1. Yes" << endl;
	cout << "\t2. No" << endl;
	cin >> choice; // Suggest choose play or no;

	if (choice == 1)
	{
		int** board = createBoard(); // Creating board;

		char* pSymbols = choiseSymbol(); // Choose symbol 'x' or 'o';

		cout << "Wonderfull! Symbol of first player: " << pSymbols[0] << "\tSymbol of second player: " << pSymbols[1] << endl;

		system("pause"); // Calling the pause;

		printBoard(board); // Printing board;
	
		while (count < 9) // We have 9 numbers on the board, that's why cicle must repit 9 times;
		{
			if (count%2 == 0) // If number is even, first player's turn;

			{
				cout << "First player choose a number 1-9: " << endl; // Suggest first player choose a number;

				if (!fillBoard(board, pSymbols[0])) // If an entered number already fill some symbol, ask user enter a number again, else fill cell first player's symbols;
				{
					continue;
				}
				printBoard(board); // Printing updated board;

				if (checkWinners(board)) // Check winner, if first player win, exit game.
				{
					cout << "First player wins! "<< endl;
					break;
				}
			}

			else // If number is uneven, second player's turn
			{
				cout << "Second player choose a number 1-9: " << endl; // Suggest second player choose a number;
				if (!fillBoard(board, pSymbols[1])) //  If an entered number already fill some symbol, ask user enter a number again, else fill cell second player's symbols;
				{
					continue;
				}
				printBoard(board);  // Printing updated board;

				if (checkWinners(board)) // Check winner, if second player win, exit game.
				{
					cout << "Second player wins! " << endl;
					break;
				}
			}
			count++;
		}
	}
	return 0;
}