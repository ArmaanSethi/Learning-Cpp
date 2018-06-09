#include <iostream>

using namespace std;

int main()
{
    for(int z = 0; z < 5; z++)
    {
        int board[25], whiteSize, blackSize, solution = 0;
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
        /*
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
        }*/


        for(int i = 0; i < whiteSize; i++)
        {
            //cout Diagonals***
            //4-diagonal
            if(((white[i]%4)==0) && (white[i] != 24))
            {
                //move down forward
                if((board[(white[i]+4)] == 0) && ((white[i]) < 20))
                {
                    if((board[(white[i]+8)] == 2) && ((white[i]) < 16))
                    {
                        solution = 1;
                        if((board[(white[i]+12)] == 2) && ((white[i]) < 12))
                        {
                            if((board[(white[i]+16)] == 2) && ((white[i]) < 8))
                            {
                                cout << (white[i]+8+1) << ", " << (white[i]+12+1) << ", " << (white[i]+16+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]+8+1) << ", " << (white[i]+12+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]+8+1) << endl;
                        }
                    }
                }
                //move down back
                if((board[(white[i]-4)] == 0) && ((white[i])  > 4))
                {
                    if((board[(white[i]+4)] == 2) && ((white[i]) < 20))
                    {
                        solution = 1;
                        if((board[(white[i]+8)] == 2) && ((white[i]) < 16))
                        {
                            if((board[(white[i]+12)] == 2) && ((white[i]) < 12))
                            {
                                cout << (white[i]+4+1) << ", " << (white[i]+8+1) << ", " << (white[i]+12+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]+4+1) << ", " << (white[i]+8+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]+4+1) << endl;
                        }
                    }
                }
                //move up forward
                if((board[(white[i]-4)] == 0) && ((white[i]) > 4))
                {
                    if((board[(white[i]-8)] == 2) && ((white[i]) > 8))
                    {
                        solution = 1;
                        if((board[(white[i]-12)] == 2) && ((white[i]) > 12))
                        {
                            if((board[(white[i]-16)] == 2) && ((white[i]) > 16))
                            {
                                cout << (white[i]-8+1) << ", " << (white[i]-12+1) << ", " << (white[i]-16+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]-8+1) << ", " << (white[i]-12+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]-8+1) << endl;
                        }
                    }
                }
                //move up back
                if((board[(white[i]+4)] == 0) && ((white[i]) < 20))
                {
                    if((board[(white[i]-4)] == 2) && ((white[i]) > 4))
                    {
                        solution = 1;
                        if((board[(white[i]-8)] == 2) && ((white[i]) > 8))
                        {
                            if((board[(white[i]-12)] == 2) && ((white[i]) > 12))
                            {
                                cout << (white[i]-4+1) << ", " << (white[i]-8+1) << ", " << (white[i]-12+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]-4+1) << ", " << (white[i]-8+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]-4+1) << endl;
                        }
                    }
                }
            }
            //6-diagonal
            if((white[i]%6)==0)
            {
                //move down forward
                if((board[(white[i]+6)] == 0) && ((white[i]) < 24))
                {
                    if((board[(white[i]+12)] == 2) && ((white[i]) < 18))
                    {
                        solution = 1;
                        if((board[(white[i]+18)] == 2) && ((white[i]) < 12))
                        {
                            if((board[(white[i]+24)] == 2) && ((white[i]) < 6))
                            {
                                cout << (white[i]+12+1) << ", " << (white[i]+18+1) << ", " << (white[i]+24+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]+12+1) << ", " << (white[i]+18+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]+12+1) << endl;
                        }
                    }
                }
                //move down back
                if((board[(white[i]-6)] == 0) && ((white[i]) > 0))
                {
                    if((board[(white[i]+6)] == 2) && ((white[i]) < 24))
                    {
                        solution = 1;
                        if((board[(white[i]+12)] == 2) && ((white[i]) < 18))
                        {
                            if((board[(white[i]+18)] == 2) && ((white[i]) < 12))
                            {
                                cout << (white[i]+6+1) << ", " << (white[i]+12+1) << ", " << (white[i]+18+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]+6+1) << ", " << (white[i]+12+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]+6+1) << endl;
                        }
                    }
                }
                //move up forward
                if((board[(white[i]-6)] == 0) && ((white[i]) > 0))
                {
                    if((board[(white[i]-12)] == 2) && ((white[i]) > 6))
                    {
                        solution = 1;
                        if((board[(white[i]-18)] == 2) && ((white[i]) > 12))
                        {
                            if((board[(white[i]-24)] == 2) && ((white[i]) > 18))
                            {
                                cout << (white[i]-12+1) << ", " << (white[i]-18+1) << ", " << (white[i]-24+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]-12+1) << ", " << (white[i]-18+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]-12+1) << endl;
                        }
                    }
                }
                //move up back
                if((board[(white[i]+6)] == 0) && ((white[i]) < 24))
                {
                    if((board[(white[i]-6)] == 2) && ((white[i]) > 0))
                    {
                        solution = 1;
                        if((board[(white[i]-12)] == 2) && ((white[i]) > 6))
                        {
                            if((board[(white[i]-18)] == 2) && ((white[i]) > 12))
                            {
                                cout << (white[i]-6+1) << ", " << (white[i]-12+1) << ", " << (white[i]-18+1) << endl;
                            }
                            else
                            {
                                cout << (white[i]-6+1) << ", " << (white[i]-12+1) << endl;
                            }
                        }
                        else
                        {
                            cout << (white[i]-6+1) << endl;
                        }
                    }
                }
            }
            //cout << "Horizontal Move Right";
            if((board[(white[i]+1)]==0)&&((white[i]%5)!=4))
            {
                if((board[white[i]+2]==2)&&((white[i]%5) != 3))
                {
                    solution = 1;
                    if((board[white[i]+3]==2)&&((white[i]%5) != 2))
                    {
                        if((board[white[i]+4]==2)&&((white[i]%5) != 1))
                        {
                            cout << (white[i]+2+1) << ", " << (white[i]+3+1) << ", " << (white[i]+4+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]+2+1) << ", " << (white[i]+3+1) << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]+2+1) << endl;
                    }
                }
            }
            //cout << "Horizontal Move Right Back";
            if((board[(white[i]-1)]==0)&&((white[i]%5)!=0))
            {
                if((board[white[i]+1]==2)&&((white[i]%5) != 4))
                {
                    solution = 1;
                    if((board[white[i]+2]==2)&&((white[i]%5) != 3))
                    {
                        if((board[white[i]+3]==2)&&((white[i]%5) != 2))
                        {
                            cout << (white[i]+1+1) << ", " << (white[i]+2+1) << ", " << (white[i]+3+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]+1+1) << ", " << (white[i]+2+1) << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]+1+1) << endl;
                    }
                }
            }
            //cout << "Horizontal Move Left";.
            if((board[(white[i]-1)]==0)&&((white[i]%5)!=0))
            {
                if((board[white[i]-2]==2)&&((white[i]%5) != 1))
                {
                    solution = 1;
                    if((board[white[i]-3]==2)&&((white[i]%5) != 2))
                    {
                        if((board[white[i]-4]==2)&&((white[i]%5) != 3))
                        {
                            cout << (white[i]-2+1) << ", " << (white[i]-3+1) << ", " << (white[i]-4+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]-2+1) << ", " << (white[i]-3+1) << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]-2+1) << endl;
                    }
                }
            }
            //cout << "Horizontal Move Left Back";***
            if((board[(white[i]+1)]==0)&&((white[i]%5)!=4))
            {
                if((board[white[i]-1]==2)&&((white[i]%5) != 0))
                {
                    solution = 1;
                    if((board[white[i]-2]==2)&&((white[i]%5) != 1))
                    {
                        if((board[white[i]-3]==2)&&((white[i]%5) != 2))
                        {
                            cout << (white[i]-1+1) << ", " << (white[i]-2+1) << ", " << (white[i]-3+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]-1+1) << ", " << (white[i]-2+1) << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]-1+1) << endl;
                    }
                }
            }
            //cout << "Vertical Move Up";***
            if((board[(white[i]-5)] == 0) && ((white[i]) > 4))
            {
                if((board[(white[i]-10)] == 2) && ((white[i]) > 9))
                {
                    solution = 1;
                    if((board[(white[i]-15)] == 2) && ((white[i]) > 14))
                    {
                        if((board[(white[i]-20)] == 2) && ((white[i]) > 19))
                        {
                            cout << (white[i]-10+1) << ", " << (white[i]-15+1) << ", " << (white[i]-20+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]-10+1) << ", " << (white[i]-15+1)  << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]-10+1) << endl;
                    }
                }
            }
            //cout << "Vertical Move Up Back";***
            if((board[(white[i]+5)] == 0) && ((white[i]) < 20))
            {
                if((board[(white[i]-5)] == 2) && ((white[i]) > 4))
                {
                    solution = 1;
                    if((board[(white[i]-10)] == 2) && ((white[i]) > 9))
                    {
                        if((board[(white[i]-15)] == 2) && ((white[i]) > 14))
                        {
                            cout << (white[i]-5+1) << ", " << (white[i]-10+1) << ", " << (white[i]-15+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]-5+1) << ", " << (white[i]-10+1)  << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]-5+1) << endl;
                    }
                }
            }
            //cout << "Veritcal Move Down";***
            if((board[(white[i]+5)] == 0) && ((white[i]) < 20))
            {
                if((board[(white[i]+10)] == 2) && ((white[i]) < 15))
                {
                    solution = 1;
                    if((board[(white[i]+15)] == 2) && ((white[i]) < 10))
                    {
                        if((board[(white[i]+20)] == 2) && ((white[i]) < 5))
                        {
                            cout << (white[i]+10+1) << ", " << (white[i]+15+1) << ", " << (white[i]+20+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]+10+1) << ", " << (white[i]+15+1)  << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]+10+1) << endl;
                    }
                }
            }
            //cout << "Vertical Move Down Back";***
            if((board[(white[i]-5)] == 0) && ((white[i]) > 4))
            {
                if((board[(white[i]+5)] == 2) && ((white[i]) < 20))
                {
                    solution = 1;
                    if((board[(white[i]+10)] == 2) && ((white[i]) < 15))
                    {
                        if((board[(white[i]+15)] == 2) && ((white[i]) < 10))
                        {
                            cout << (white[i]+5+1) << ", " << (white[i]+10+1) << ", " << (white[i]+15+1) << endl;
                        }
                        else
                        {
                            cout << (white[i]+5+1) << ", " << (white[i]+10+1)  << endl;
                        }
                    }
                    else
                    {
                        cout << (white[i]+5+1) << endl;
                    }
                }
            }
        }
        if(solution == 0)
        {
            cout << "NONE" << endl;
        }
    }
    return 0;

}
