/****************************************************************
*Programmer: Fang Yu Lim                                        *
*Programming Assignment: CptS122 PA4                            *
* Date: Oct12,2020                                              *
* Description: Hunt the Wumpus Game                             *
*                                                               *
***************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <array>

using namespace std;

class GameWorld
{
private:
	//5 x5 grid
	char board[5][5];
	int positionX;
	int positionY;
	int points = 0;
	char tempBoard[5][5];

public:
	//setter for points
	void setPoints(int p)
	{
		points = p;
	}
	//getter for points
	int getPoints()
	{
		return points;
	}
	//constructor
	GameWorld();
	
	//setting traps
	int noTraps();
	void trapPosition(int trap);
	
	//setting enemy position
	void EnemyPosition();

	//setting gold position
	void GoldPosition();

	//setting player position
	void PlayerPosition();

	//displays all one square away from player
	void displayVisibleWorld();
	
	//displays whole grid
	void displayWhole();

	//player movements 
	int moveUp();
	int moveDown();
	int moveRight();
	int moveLeft();

	//checking for win/continue
	bool haveIWon();

	//check if alive/not (if I hit wumpus/pit)
	bool amIAlive();

	//restart with same player
	void restartSame();

	//restart with new player
	void restartDif(GameWorld object)
	{
		cout << "New map" << endl;
		object = GameWorld();
	}



};



