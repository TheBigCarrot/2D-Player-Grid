#include <iostream>
#include <array>
#include <vector>
#include <conio.h>
#include <stdio.h>
using namespace std;


void displayMap(vector<int> row1, vector<int> row2, vector<int> row3, vector<int> row4, int x, int y)
{
    cout << "Current Map:\n";
    cout << "xlocation: " << x << endl;
    cout << "ylocation: " << y << endl;
    for (int i = 0; i < row1.size(); i++)
    {
        cout << row1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < row2.size(); i++)
    {
        cout << row2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < row3.size(); i++)
    {
        cout << row3[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < row4.size(); i++)
    {
        cout << row4[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> row1 = { 1, 0, 0, 0, }; //rows 1 through 4 locates where the player is on the x-axis
    vector<int> row2 = { 0, 0, 0, 0, }; //most of the code assumes that all vectors are the same size
    vector<int> row3 = { 0, 0, 0, 0, };
    vector<int> row4 = { 0, 0, 0, 0, };
    int xlocation = 1;
    int ylocation = 1;
    vector<int> rows = { 1, 0, 0, 0, }; //this locates which row/y-axis the player is in. It's kind of pointless

    cout << "Press 'P' at any time to exit the game.\n";
    displayMap(row1, row2, row3, row4, xlocation, ylocation);
    bool keepPlaying = true;
    char input;

    while (keepPlaying == true)
    {

        input = _getch();
        if (input == 'p')
        {
            keepPlaying = false;
        }
        if (input == 'd')
        {
            if (xlocation == 4)
            {
                cout << "No spaces available to the right.\n";
            }
            else
            {
                switch (ylocation)
                {
                case 1:
                    row1.insert(row1.begin() , 0);
                    row1.pop_back();
                    xlocation++;
                    break;

                case 2:
                    row2.insert(row2.begin() , 0);
                    row2.pop_back();
                    xlocation++;
                    break;

                case 3:
                    row3.insert(row3.begin(), 0);
                    row3.pop_back();
                    xlocation++;
                    break;

                case 4:
                    row4.insert(row4.begin(), 0);
                    row4.pop_back();
                    xlocation++;
                    break;

                default:
                    break;
                }       
            }
        }
        if (input == 'a')
        {
            if (xlocation == 1)
            {
                cout << "No spaces available to the left.\n";
            }
            else
            {
                switch (ylocation)
                {
                case 1:
                    row1.erase(row1.begin());
                    row1.push_back(0);
                    xlocation--;
                    break;

                case 2:
                    row2.erase(row2.begin());
                    row2.push_back(0);
                    xlocation--;
                    break;

                case 3:
                    row3.erase(row3.begin());
                    row3.push_back(0);
                    xlocation--;
                    break;

                case 4:
                    row4.erase(row4.begin());
                    row4.push_back(0);
                    xlocation--;
                    break;

                default:
                    break;
                }
            }
        }
        if (input == 's')
        {
            switch (ylocation)
            {
            case 1:
                for (int i = 0; i < row1.size(); i++)
                {
                    row1.push_back(0);
                    row1.erase(row1.begin());
                }
                row2.clear();
                for (int i = 0; i < row1.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row2.push_back(1);
                    }
                    else
                    {
                        row2.push_back(0);
                    }
                }
                ylocation++;
                break;

            case 2:
                for (int i = 0; i < row2.size(); i++)
                {
                    row2.push_back(0);
                    row2.erase(row2.begin());
                }
                row3.clear();
                for (int i = 0; i < row2.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row3.push_back(1);
                    }
                    else
                    {
                        row3.push_back(0);
                    }
                }
                ylocation++;
                break;

            case 3:
                for (int i = 0; i < row3.size(); i++)
                {
                    row3.push_back(0);
                    row3.erase(row3.begin());
                }
                row4.clear();
                for (int i = 0; i < row3.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row4.push_back(1);
                    }
                    else
                    {
                        row4.push_back(0);
                    }
                }
                ylocation++;
                break;

            case 4:
                cout << "No spaces available below.\n";
                break;

            default:
                break;
            }
        }
        if (input == 'w')
        {
            switch (ylocation)
            {
            case 1:
                cout << "No spaces available above.\n";
                break;

            case 2:
                for (int i = 0; i < row2.size(); i++)
                {
                    row2.push_back(0);
                    row2.erase(row2.begin());
                }
                row1.clear();
                for (int i = 0; i < row2.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row1.push_back(1);
                    }
                    else
                    {
                        row1.push_back(0);
                    }
                }
                ylocation--;
                break;

            case 3:
                for (int i = 0; i < row3.size(); i++)
                {
                    row3.push_back(0);
                    row3.erase(row3.begin());
                }
                row2.clear();
                for (int i = 0; i < row3.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row2.push_back(1);
                    }
                    else
                    {
                        row2.push_back(0);
                    }
                }
                ylocation--;
                break;

            case 4:
                for (int i = 0; i < row4.size(); i++)
                {
                    row4.push_back(0);
                    row4.erase(row4.begin());
                }
                row3.clear();
                for (int i = 0; i < row4.size(); i++)
                {
                    if (i == (xlocation - 1))
                    {
                        row3.push_back(1);
                    }
                    else
                    {
                        row3.push_back(0);
                    }
                }
                ylocation--;
                break;

            default:
                break;
            }
        }
        displayMap(row1, row2, row3, row4, xlocation, ylocation);
        cout << "You pressed: " << input << endl;
    }
}