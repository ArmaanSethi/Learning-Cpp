#include <windows.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

COORD coord = {0,0};

using namespace std;

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string getWord(string s, int l)
{
    string word;
    sort(s.begin(), s.end());
    for(int i = l-1; i >= 0; i--)
    {
        word+= s[i];
    }
    cout << word << endl;
    return word;
}

void output(string w1, string w2, int digit)
{
    system("CLS");
    int xcross = w1.find((digit+'0'));
    int ycross = w2.find((digit+'0'));
    //cout << xcross << ycross;
    for(int i = 0; i < w2.length(); i++)
    {
        gotoxy(xcross*3, i*2);
        cout << w2[i];
    }
    for(int i = 0; i < w1.length(); i++)
    {
        gotoxy(i*3, ycross*2);
        cout << w1[i];
    }
    gotoxy(0,25);
}

int main()
{
    string s1, s2, w1, w2;
    int l1, l2, digit;
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < 6; i++)
    {
        gotoxy(30,0);
        cin >> l1;
        cin >> l2;
        cin >> digit;
        w1 = getWord(s1,l1);
        w2 = getWord(s2,l2);
        output(w1,w2,digit);
    }
    return 0;
}
