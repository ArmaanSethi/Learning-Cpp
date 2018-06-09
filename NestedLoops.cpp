/*Armaan Sethi
* NestedLoops
* 10/11/12
*/
#include <iostream>
#include <iomanip>

using namespace std;


void input(int &h, int &s)
{
    cout << "Height: " << endl;
    cin >> h;
    if ( h > 47)
    {
        cout << "Height is too large. Give a smaller height (Less than 47)"<< endl;
        cin >> h;
    }
    s = 0;
    cout << endl;

}

void output(int h, int s)
{
    for (int spaces = (h - 8); spaces > 0; spaces--)
        cout << " ";
    cout << "^" << endl;
    for (int spaces = (h - 10); spaces > 0; spaces--)
        cout << " ";
    cout << "<*X*>" << endl;
    for (int spaces = (h - 9); spaces > 0; spaces--)
        cout <<" ";
    cout << ">-<" << endl;
    for (int spaces = (h - 10); spaces > 0; spaces--)
        cout << " ";
    cout << "<*X*>" << endl;
    for (int spaces = (h - 8); spaces > 0; spaces--)
        cout << " ";
    cout << "_" << endl;


    for (int ih = (h*2); ih > 15 ; ih = (ih - 2))
    {
        for (int spaces = (ih / 2) - 8; spaces > 0; spaces--)
        {
            cout << " ";
        }
        for (int counter = ih; counter <= (h*2) ; counter++)
        {
            if (s % 10 == 1)
            {
                cout << "*";
            }
            else if (s % 10 == 2)
            {
                cout << "0";
            }
            else if (s % 10 == 5)
            {
                cout << "@";
            }
            else if (s % 10 == 8)
            {
                cout << "@";
            }
            else
            {
                cout << "*";
            }
            s++;
        }
        cout << endl;
    }

    for (int spaces = (h - 10); spaces > 0; spaces--)
        cout <<" ";
    cout <<"[[|]]" << endl;
    for (int spaces = (h - 10
                       ); spaces > 0; spaces--)
        cout <<" ";
    cout <<"[[|]]" << endl;
}

int main()
{
    int height, seed;

    input(height, seed);
    output(height, seed);
}
