#include <windows.h>
#include<iostream>
#include<stdio.h>

COORD coord = {0,0};

using namespace std;

class Piece {
private:
    int x, y, color;
public:
    Piece() {
        x = y = color = -1;
    }
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    int getcolor() {
        return color;
    }
    void setcolor(int c) {
        color = c;
    }
    void set(int xpos, int ypos, int c) {
        x = xpos;    //start of the game
        y = ypos;
        color = c;
    }
    void set(int xpos, int ypos) {
        x = xpos;    //placing
        y = ypos;
    }
    void display();
};

class Board {
private:
    Piece list[81];
    int x1, y1, status, redp, blackp, winner;//Where it will be placed. Turn, Number on Board, Who Wins.
    void move();//everything goes inside this
    int inRange(int x, int y);//if it is a valid input
    int pieceatLoc(int x, int y);//if there is already a piece
    int validplace(int x, int y);//if it can be placed
    void display();
public:
    Board() {};
    void execute();
};

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Piece::display() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    //if(x > 0) {
    gotoxy(3*x,2*y);
    if(color == 0) {
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x1F);
        cout << "X" << endl;
    }
    if(color == 1) {
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x1C);
        cout << "O" << endl;
    }
    //}
}

void Board::display() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x1A);
    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            cout << char(178) << " ";
        } else {
            cout << " " << i << " ";
        }
    }
    cout << endl;
    for(int j = 1; j < 10; j++) {
        cout << "                             " << endl << j << "                            " << endl;
    }
    cout << "                             " << endl;
}

void Board::execute() {
    winner = -1;
    status = 0;
    display();
    for(int i = 0; i < 64; i++) {
        list[i].display();
    }
    while(winner < 0) {
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F);
        gotoxy(30,0);
        int x, y;
        cout << "(X Y): ";
        cin >> x;
        cin >> y;
        list[4].set(x,y,(status%2));
        for(int i = 0; i < 64; i++) {
            list[i].display();
        }
        status++;
    }
}

int main() {
    Board TTT;
    TTT.execute();
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F);
    gotoxy(0,20);
}
