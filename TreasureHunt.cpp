#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void setup(char display[][5], char real_board[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for(int a = 0; a < 5; a++)
        {
            display[i][a] = '#';
            real_board[i][a] = '#';
        }
    }

    for(int i = 0; i < 10; i++)
    {
        int x = rand()%5 + 0;
        int y = rand()%5 + 0;
        if (real_board[x][y] == '$')
            {
                x = rand()%5 + 0;
                y = rand()%5 + 0;
                real_board[x][y] = '$';
            }
            else
            {
                real_board[x][y] = '$';
            }
    }

}

void output(char display[][5], char real[][5])
{
    cout << endl << "   1  2  3  4  5" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl << i + 1;
        for(int a = 0; a < 5; a++)
        {
            cout <<  setw(3) << display[i][a];
        }
        cout << endl ;
    }

    cout << endl << "   1  2  3  4  5" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl << i + 1;
        for(int a = 0; a < 5; a++)
        {
            cout << setw(3) << real[i][a];
        }
        cout << endl;
    }
    cout << endl;
}

void input(char display[][5],char real_board[][5], int &guesses)
{
    cout << "There are 10 Treasures and 25 spaces. Guess where the Treasures are!" << endl;
    guesses = 0;
    int treasures = 10;
    int x, y;
    do
    {
        output(display, real_board);
        cout << "X : ";
        cin >> x;
        cout << "Y : ";
        cin >> y;

        if( x > 5 || x < 1 || y > 5 || y < 1)
        {
            cout << "X and Y must be between 1 and 5" << endl;
            cout << "X : ";
            cin >> x;
            cout << "Y : ";
            cin >> y;
        }
        if(real_board[x - 1][y - 1] == '$' && display[x - 1][y - 1] == '#')
        {
            treasures--;
            display[x - 1][y - 1] = '$';
            real_board[x - 1][y - 1] == '#';
            cout << endl << "You Found a Treasure!" << endl;
        }
        else
        {
            display[x - 1][y - 1] = ' ';
            cout << endl << "You Found Nothing" << endl;
        }
        guesses++;

    }while(treasures != 0);
}


int main()
{
    int user_guess[5][5], guesses;
    char display[5][5], real_board[5][5];

    srand(time(0));

    setup(display, real_board);
    input(display, real_board, guesses);
    output(display, real_board);

    cout << "Number of Guesses : " << guesses;
    return 0;
}