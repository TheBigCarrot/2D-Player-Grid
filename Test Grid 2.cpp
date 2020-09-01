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

void ShowMap(int plane[16][16], int x, int y, int alert, int x_max, int y_max)
{
	system("cls");  //This is windows only. This will be fixed later.
	cout << "Map Location:\n";
	cout << "X locaiton = " << x + 1<< endl;
	cout << "Y location = " << y + 1<< endl;
	for (int c = 0; c < x_max; c++)
	{
		for (int r = 0; r < y_max; r++)
		{
			switch (plane[c][r])
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
	int plane[16][16] = { //when changing map size, change dimensions here.
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, },
		{ 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	};
	int x = 0; //x goes from 0 to 9 since arrays start at 0. it will make the code easier.
	int y = 0; //y goes from 0 to 9 since arrays start at 0. it will make the code easier.
	const int x_max = 16; //when changing map size, change dimension size here.
	const int y_max = 16; //when changing map size, change dimension size here.
	char input;
	int alert;

	ShowMap(plane, x, y, 1, x_max, y_max);


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
			if (y == y_max - 1 || plane[x][y + 1] == 2)
			{
				alert = 4;
			}
			else
			{
				plane[x][y] = 0;
				plane[x][y + 1] = 1;
				y++;
			}
		}
		if (input == 'a')
		{
			if (y == 0 || plane[x][y - 1] == 2)
			{
				alert = 5;
			}
			else
			{
				plane[x][y] = 0;
				plane[x][y - 1] = 1;
				y--;
			}
		}
		if (input == 's')
		{
			if (x == x_max - 1 || plane[x + 1][y] == 2)
			{
				alert = 2;
			}
			else
			{
				plane[x][y] = 0;
				plane[x + 1][y] = 1;
				x++;
			}
		}
		if (input == 'w')
		{
			if (x == 0 || plane[x - 1][y] == 2)
			{
				alert = 3;
			}
			else
			{
				plane[x][y] = 0;
				plane[x - 1][y] = 1;
				x--;
			}
		}

		ShowMap(plane, x, y, alert, x_max, y_max);

	}
}
