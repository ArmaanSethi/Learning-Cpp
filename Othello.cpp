#include<iostream>

using namespace std;

class Piece
{
private:
    int x, y, color;
public:
    Piece()
    {
        x = y = color = -1;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    int getcolor()
    {
        return color;
    }
    void setcolor(int c)
    {
        color = c;
    }
    void set(int xpos, int ypos, int c)
    {
        x = xpos;    //start of the game
        y = ypos;
        color = c;
    }
    void set(int xpos, int ypos)
    {
        x = xpos;    //placing
        y = ypos;
    }
    void display();
};

class Board
{
private:
    Piece list[64];
    int x1, y1, status, redp, blackp, winner;//Where it will be placed. Turn, Number on Board, Who Wins.
    void move();//everything goes inside this
    int inRange(int x, int y);//if it is a valid input
    int pieceatLoc(int x, int y);//if there is already a piece
    int validplace(int x, int y);//if it can be placed
    void display();
public:
    Board(){};
    void execute();
};

void Board::execute()
{
    int x, y;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

}

int main()
{
    Board Othello;
    Othello.execute();
    return 0;
}
