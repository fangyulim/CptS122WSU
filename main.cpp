#include "header.h"
int main()
{
	//opening file for saving score
	ofstream file;
	file.open("GameScores.txt");

	//player name
	string name;
	cout << "Please enter player name" << name << endl;
	cin >> name;
	file << "player:" << name << endl;


	GameWorld world;
	char choice;
	int val;
	// do while player does not choose to end the game (Q/q)
		do {

			cout << "press I/i to move up." << endl;
			cout << "press K/k to move down." << endl;
			cout << "press j/J to move left." << endl;
			cout << "press l/L to move right." << endl;
			cout << "press V/v to display Visible World." << endl;
			cout << "press C/c to display Entire World." << endl;
			cout << "Press R/r to restart the game with the same player." << endl;
			cout << "press N/n to restart with a new player." << endl;
			cout << "press Q/q to quit." << endl;
			cin >> choice;

			switch (choice)
			{
			//Cheat to show whole map(c/C)
			case 'C':
			case 'c':
				world.displayWhole();
				file << world.getPoints() << endl;
				break;

			// move player up (i/I)
			case 'I':
			case 'i':
				 val= world.moveUp();
				if (val == 0)
				{
					world = GameWorld();
					cout << "You lost. Resetting the map\n";
				}
				else if (val == 1)
				{
					world = GameWorld();
					cout << "You won. Resetting the map\n";
				}
				file << world.getPoints() << endl;
				
				break;

			//move player left (J/j)
			case 'J':
			case'j':
				val = world.moveLeft();
				if (val == 0)
				{
					world = GameWorld();
					cout << "You lost. Resetting the map\n";
				}
				else if (val == 1)
				{
					world = GameWorld();
					cout << "You won. Resetting the map\n";
				}
				file << world.getPoints() << endl;
				break;

			//move player left (L/l
			case 'L':
			case 'l':
				val=world.moveRight();
				if (val == 0)
				{
					world = GameWorld();
					cout << "You lost. Resetting the map\n";
				}
				else if (val == 1)
				{
					world = GameWorld();
					cout << "You won. Resetting the map\n";
				}
				file << world.getPoints() << endl;
				break;

			//Move player down (K/k)
			case 'k':
			case 'K':
				val=world.moveDown();
				if (val == 0)
				{
					world = GameWorld();
					cout << "You lost. Resetting the map\n";
				}
				else if (val == 1)
				{
					world = GameWorld();
					cout << "You won. Resetting the map\n";
				}
				file << world.getPoints() << endl;
				break;

			//Displays squares one away from player(V/v)
			case 'V':
			case 'v':
				world.displayVisibleWorld();
				if (val == 0)
				{
					world = GameWorld();
					cout << "You lost. Resetting the map\n";
				}
				else if (val == 1)
				{
					world = GameWorld();
					cout << "You won. Resetting the map\n";
				}
				file << world.getPoints() << endl;
				break;

			//Restart with same player(R/r)
			case 'R':
			case 'r':
				world.restartSame();
				file << "Game restart\n";
				file << world.getPoints() << endl;
				break;

			//Restart with new player(N/n)
			case 'N':
			case 'n':
				world = GameWorld();
				world.setPoints(0);
				cout << "Please enter player name" << endl;
				cin >> name;
				file << "player:" <<name<< endl;
				file << "Game restart\n";
				file << world.getPoints() << endl;
				break;

			//End game (Q/q)
			case 'Q':
			case 'q':
				cout << "Thank you!" << endl;
				file.close();
				break;
			}
		} while (choice != 'q' &&  choice != 'Q');

	
}