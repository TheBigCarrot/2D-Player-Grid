#include <iostream>
#include <array>
#include <vector>
#include <conio.h>
#include <stdio.h>

using namespace std;

void Alert(int alert)  //this is how the game will send a message to the player. (If the player cant move, found an item, lost health, etc.)
{
	switch (alert)
	{
	case 0:
		break;

	case 1:
		cout << "Press 'P' at any time to quit playing.\n";
		break;

	case 2:
		cout << "Unable to move down.\n";
		break;

	case 3:
		cout << "Unable to move up.\n";
		break;

	case 4:
		cout << "Unable to move to the right.\n";
		break;

	case 5:
		cout << "Unable to move to the left.\n";
		break;

	default:
		break;
	}
}

void ShowMap(int plane[4][16][16], int x, int y, int level, int alert, int x_max, int y_max)
{
	system("cls");  //This is windows only. This will be fixed later.
	cout << "Map Location:\n";
	cout << "X locaiton = " << x + 1<< endl;
	cout << "Y location = " << y + 1<< endl;
	cout << "Level Location: " << level + 1 << endl;
	for (int c = 0; c < x_max; c++)
	{
		for (int r = 0; r < y_max; r++)
		{
			switch (plane[level][c][r])
			{
			case 0:
				cout << '.' << " ";
				break;

			case 1:
				cout << '@' << " ";
				break;

			case 2:
				cout << '#' << " ";
				break;

			case 3:
				cout << '0' << " ";
				break;

			case 4:
				cout << '0' << " ";
				break;

			default:
				break;
			}

		}
		cout << endl;
	}
	Alert(alert);
}

int main()
{
	int plane[4][16][16] = { { //when changing map size, change dimensions here.
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, },
	}, {
		{ 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, },
	}, {
		{ 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, },
	}, {
		{ 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	} };
	int x = 0; //x goes from 0 to 9 since arrays start at 0. it will make the code easier.
	int y = 0; //y goes from 0 to 9 since arrays start at 0. it will make the code easier.
	int level = 0; //this is a pointer for which 2d plane the charcter is currently moving on
	const int x_max = 16; //when changing map size, change dimension size here.
	const int y_max = 16; //when changing map size, change dimension size here.
	char input;
	int alert;

	/*
	NOTE TO SELF: ARRAYS START AT 0
	*/

	ShowMap(plane, x, y, level, 1, x_max, y_max);


	while (true)
	{
		alert = 0;

		input = _getch();  //I think this is windows only. This will be fixed later.
		if (input == 'p')
		{
			break;
		}
		if (input == 'd')
		{
			if (x == x_max - 1 || plane[level][y][x + 1] == 2)
			{
				alert = 4;
			}
			else if (plane[level][y][x + 1] == 4)
			{
				plane[level][y][x] = 0;
				y = 1;
				plane[level + 1][y][x + 1] = 1;
				x++;
				level++;
			}
			else if (plane[level][y][x + 1] == 3)
			{
				plane[level][y][x] = 0;
				y = 14;
				plane[level - 1][y][x + 1] = 1;
				x++;
				level--;
			}
			else
			{
				plane[level][y][x] = 0;
				plane[level][y][x + 1] = 1;
				x++;
			}
		}
		if (input == 'a')
		{
			if (x == 0 || plane[level][y][x - 1] == 2)
			{
				alert = 5;
			}
			else if (plane[level][y][x - 1] == 4)
			{
				plane[level][y][x] = 0;
				y = 1;
				plane[level + 1][y][x - 1] = 1;
				x--;
				level++;
			}
			else if (plane[level][y][x - 1] == 3)
			{
				plane[level][y][x] = 0;
				y = 14;
				plane[level - 1][y][x - 1] = 1;
				x--;
				level--;
			}
			else
			{
				plane[level][y][x] = 0;
				plane[level][y][x - 1] = 1;
				x--;
			}
		}
		if (input == 's')
		{
			if (y == y_max - 1 || plane[level][y + 1][x] == 2)
			{
				alert = 2;
			}
			else if (plane[level][y + 1][x] == 4)
			{
				plane[level][y][x] = 0;
				y = 1;
				plane[level + 1][y][x] = 1;
				level++;
			}
			else if (plane[level][y + 1][x] == 3)
			{
				plane[level][y][x] = 0;
				y = 14;
				plane[level - 1][y][x] = 1;
				level--;
			}
			else
			{
				plane[level][y][x] = 0;
				plane[level][y + 1][x] = 1;
				y++;
			}
		}
		if (input == 'w')
		{
			if (y == 0 || plane[level][y - 1][x] == 2)
			{
				alert = 3;
			}
			else if (plane[level][y - 1][x] == 4)
			{
				plane[level][y][x] = 0;
				y = 1;
				plane[level][y][x] = 1;
				level++;
			}
			else if (plane[level][y - 1][x] == 3)
			{
				plane[level][y][x] = 0;
				y = 14;
				plane[level - 1][y][x] = 1;
				level--;
			}
			else
			{
				plane[level][y][x] = 0;
				plane[level][y - 1][x] = 1;
				y--;
			}
		}

		ShowMap(plane, x, y, level, alert, x_max, y_max);

	}
}