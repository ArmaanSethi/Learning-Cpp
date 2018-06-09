#include <iostream>

using namespace std;


int main()
{
    int board[25], whiteSize, blackSize;
    for(int i = 0; i < 25; i++)
    {
        board[i] = 0;
    }
    cin >> whiteSize;
    int white[whiteSize];
    for(int i = 0; i < whiteSize; i++)
    {
        cin >> white[i];
        white[i]--;
        board[white[i]] = 1;
    }
    cin >> blackSize;
    int black[blackSize];
    for(int i = 0; i < blackSize; i++)
    {
        cin >> black[i];
        black[i]--;
        board[black[i]] = 2;
    }
    //
    cout << "PosW:  ";
    for(int i = 0; i < whiteSize; i++)
    {
        cout << white[i] << "  ";
    }
    cout << endl;
    cout <<"PosB:   ";
    for(int i = 0; i < blackSize; i++)
    {
        cout << black[i]<< "  ";
    }
    cout << endl;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << board[(5*i)+j] << "  ";
        }
        cout << endl;
    }
    //

    for(int i = 0; i < whiteSize; i++)
    {
        //cout Diagonals
        //cout << "Horizontal Move Right";
        if((board[(white[i]+1)]==0)&&((white[i]%5)!=4))
        {
            if((board[white[i]+2]==2)&&((white[i]%5) != 3))
            {
                if((board[white[i]+3]==2)&&((white[i]%5) != 2))
                {
                    cout << (white[i]+2+1) << ", " << (white[i]+3+1) << endl;
                }else
                {
                    cout << (white[i]+2+1) << endl;
                }
            }
        }
        //cout << "Horizontal Move Right Back";
        //cout << "Horizontal Move Left";.
        if((board[(white[i]-1)]==0)&&((white[i]%5)!=0))
        {
            if((board[white[i]-2]==2)&&((white[i]%5) != 1))
            {
                if((board[white[i]-3]==2)&&((white[i]%5) != 2))
                {
                    cout << (white[i]-2+1) << ", " << (white[i]-3+1) << endl;
                }else
                {
                    cout << (white[i]-2+1) << endl;
                }
            }
        }
        //cout << "Horizontal Move Left Back";
        //cout << "Vertical Move Up";
        //cout << "Vertical Move Up Back";
        //cout << "Veritcal Move Down";
        //cout << "Vertical Move Down Back";
    }


    return 0;

}
