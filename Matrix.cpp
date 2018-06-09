#include<iostream>
#include<vector>
#include<fstream>
#include<string>


using namespace std;

int main()
{
    int size = 0;
    vector<string> input;
    string temp;
    int more = 0;
    ifstream infile("H://QUOTES.txt");
    //for(int i = 0; i < 5; i++)
    while(more == 0)
    {
        cout <<"input: ";
        cin >> temp;
        input.push_back(temp);
        cout << "Continue inputting? (1 to exit): " ;
        cin >> more;
    }

    for(int i = 0; i < input.size(); i++)
    {
        input[i].erase(1,1);
        cout << input[i] << " ";
        if((input[i][0] == 'A')&&(size < 1))
            size = 1;
        if((input[i][0] == 'B')&&(size < 2))
            size = 2;
        if((input[i][0] == 'C')&&(size < 3))
            size = 3;
        if((input[i][0] == 'D')&&(size < 4))
            size = 4;
        if((input[i][0] == 'E')&&(size < 5))
            size = 5;
        if((input[i][1] == 'A')&&(size < 1))
            size = 1;
        if((input[i][1] == 'B')&&(size < 2))
            size = 2;
        if((input[i][1] == 'C')&&(size < 3))
            size = 3;
        if((input[i][1] == 'D')&&(size < 4))
            size = 4;
        if((input[i][1] == 'E')&&(size < 5))
            size = 5;
    }
    size;
    cout << "SIZE: " << size;
    int matrix[size][size];

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = 0;

    cout << "patharray" << endl;
    int path[size][2];
    int x;
    int y;
    for(int i = 0; i < input.size(); i++)
    {
        if((input[i][0] == 'A'))
            x=0;
        if((input[i][0] == 'B'))
            x=1;
        if((input[i][0] == 'C'))
            x=2;
        if((input[i][0] == 'D'))
            x=3;
        if((input[i][0] == 'E'))
            x=4;
        if((input[i][1] == 'A'))
            y=0;
        if((input[i][1] == 'B'))
            y=1;
        if((input[i][1] == 'C'))
            y=2;
        if((input[i][1] == 'D'))
            y=3;
        if((input[i][1] == 'E'))
            y=4;
       //cout << x << endl;
        //cout << y << endl;
        matrix[x][y] = 1;
    }
    /*cout << "solutionarray" << endl;
    for(int i = 0; i < size; i++)
    {
        int x = path[i][0];
        cout << x << endl;
        int y = path[i][1];
        cout << y << endl;
        matrix[x][y] = 1;
    }*/
    //cout <<"outputarray" << endl;
    cout << endl << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << matrix[i][j];
        }cout << endl;
    }



}
