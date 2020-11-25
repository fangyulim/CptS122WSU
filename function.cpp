#include "header.h"

//random number of traps between 5-10
int GameWorld::noTraps()
{	
	srand(time(NULL));
	return 5+rand() % (10 + 1 - 5);
}

//setting random trap position
void GameWorld::trapPosition(int trap)
{
	int x, y;
	// setting everything to '-'
	memset(board, '-', sizeof(board[0][0]) * 5 * 5);
	for (int i = 0; i < trap; i++)
	{
		x = rand() % 5; //give range between 0-5
		y = rand() % 5;

		while(board[x][y] == 'T')
		{
			x = rand() % 5; //give range between 0-5
			y = rand() % 5;
		}

		board[x][y] = 'T';
	}

}

//setting random enemy position
void GameWorld::EnemyPosition()
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;
	while (board[x][y] == 'T')
	{
		x = rand() % 5; //give range between 0-5
		y = rand() % 5;
	}

	board[x][y] = 'E';
}

//setting random gold position
void GameWorld::GoldPosition()
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;
	while (board[x][y] == 'T' || board[x][y]=='E')
	{
		x = rand() % 5; //give range between 0-5
		y = rand() % 5;
	}

	board[x][y] = 'G';
}

//setting random player position
void GameWorld::PlayerPosition()
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;
	while (board[x][y] == 'T' || board[x][y] == 'E' || board[x][y] == 'G')
	{
		x = rand() % 5; //give range between 0-5
		y = rand() % 5;
	}

	board[x][y] = 'P';
	positionX = x;
	positionY = y;
	memcpy(tempBoard,board, sizeof(board[0][0]) * 5 * 5);
}

//displaying whole grid(cheat)
void GameWorld::displayWhole()
{
	if (points >=5)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		points -= 5;
	}
	else
		cout << "You don't have enough points." << endl;

}

//displaying all squares one away from player
void GameWorld::displayVisibleWorld()
{
	if (points >= 2)
	{
		int x = positionX - 1;
		int y = positionY - 1;
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				if (i <= 4 && j <= 4 && i >= 0 && j >= 0)
					cout << board[i][j] << " ";
			}
			cout << endl;
		}
		points -= 2;
	}
	else
		cout << "You don't have enough points." << endl;

}

//player movement: up
int GameWorld::moveUp()
{
	bool alive_status, win_status;
	if (positionX - 1 < 0)
	{
		cout << "Invalid enter. Please enter a different movement." << endl;
	}
	else
	{
		positionX--;
		cout << "Player moved up" << endl;
		win_status= haveIWon();
		alive_status=amIAlive();
		if (alive_status == false)
		{
			cout << "You have lost." << endl;
			return 0;
		}
		else if (win_status == true)
		{
			cout << "You have won." << endl;
			return 1;
		}
		else
		{
			board[positionX][positionY] = 'P';
			board[positionX + 1][positionY] = '-';
			return -1;
		}
	}
}

//player movement:down
int GameWorld::moveDown()
{
	bool alive_status, win_status;
	if (positionX +1 >4)
	{
		cout << "Invalid enter. Please enter a different movement." << endl;
		
	}
	else
	{
		positionX++;
		cout << "Player moved down" << endl;
		win_status = haveIWon();
		alive_status = amIAlive();
		if (alive_status == false)
		{
			cout << "You have lost." << endl;
			return 0;
		}
		else if (win_status == true)
		{
			cout << "You have won." << endl;
			return 1;
		}
		else
		{
			board[positionX][positionY] = 'P';
			board[positionX - 1][positionY] = '-';
			return -1;
		}
	}
}

//player movement: left
int GameWorld::moveLeft()
{
	bool alive_status, win_status;
	if (positionY - 1 < 0)
	{
		cout << "Invalid enter. Please enter a different movement." << endl;
	}
	else
	{
		positionY--;
		cout << "Player moved left" << endl;
		win_status = haveIWon();
		alive_status = amIAlive();
		if (alive_status == false)
		{
			cout << "You have lost." << endl;
			return 0;
		}
		else if (win_status == true)
		{
			cout << "You have won." << endl;
			return 1;
		}
		else
		{
			board[positionX][positionY] = 'P';
			board[positionX][positionY + 1] = '-';
			return -1;
		}
	}
}

//player movement right
int GameWorld::moveRight()
{
	bool alive_status, win_status;
	if (positionY + 1 >4)
	{
		cout << "Invalid enter. Please enter a different movement." << endl;
	}
	else
	{
		positionY++;
		cout << "Player moved right" << endl;
		win_status = haveIWon();
		alive_status = amIAlive();
		if (alive_status == false)
		{
			cout << "You have lost." << endl;
			return 0;
		}
		else if (win_status == true)
		{
			cout << "You have won." << endl;
			return 1;
		}
		else
		{
			board[positionX][positionY] = 'P';
			board[positionX][positionY - 1] = '-';
			return -1;
		}
	}
}

//check for win/lose
bool GameWorld::haveIWon()
{
	if (board[positionX][positionY] == 'G')
	{
		cout << points << endl;
		points = 0;
		return true;

	}
	else
		return false;
}

//check if alive/dead
bool GameWorld::amIAlive()
{
	if (board[positionX][positionY] == 'E' || board[positionX][positionY] == 'T')
	{
		points = 0;
		return false;
	}
	else
	{
		points += 5;
		return true;
	}
}

//restart with same player
void GameWorld::restartSame()
{
	memcpy(board,tempBoard, sizeof(tempBoard[0][0]) * 5 * 5);
	points = 0;
}


//constructor
GameWorld::GameWorld()
{
	int Trap = noTraps();
	trapPosition(Trap);
	EnemyPosition();
	GoldPosition();
	PlayerPosition();
	
};
