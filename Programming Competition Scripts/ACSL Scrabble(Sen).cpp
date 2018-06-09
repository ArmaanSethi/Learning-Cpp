#include<iostream>

using namespace std;

int score(int point[], int &pos, char dir)
{
    int multiplier = 1, sum = 0;
    for(int i= 0; i < 4; i++)
    {
        sum += point[i];
        if(((pos % 3) == 0) && ((pos % 2) != 0))
            sum += point[i];
        else if((pos % 5) == 0)
            sum += (point[i] * 2);
        else if((pos % 7) == 0)
            multiplier *= 2;
        else if((pos % 8) == 0)
            multiplier *= 3;
        if(dir == 'H') pos++;
        if(dir == 'V') pos+=10;
    }
    cout << "S: " << (sum * multiplier) << endl;
    return (sum * multiplier);
}

int main()
{
    char letter, direction[3];
    int position[3], point[4], total = 0;
    for(int i = 0; i < 4; i++)
    {
        cin >> letter;
        if((letter == 'A') || (letter == 'E')) point[i] = 1;
        if((letter == 'D') || (letter == 'R')) point[i] = 2;
        if((letter == 'B') || (letter == 'M')) point[i] = 3;
        if((letter == 'V') || (letter == 'Y')) point[i] = 4;
        if((letter == 'J') || (letter == 'X')) point[i] = 8;
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> position[j];
            cin >> direction[j];
        }
        for(int j = 0; j < 3; j++)
        {
            int temp = score(point, position[j], direction[j]);
            cout << "T1: " << total << endl;
            if(temp > total)
            {
                total = temp;
            }
            cout << "T2: " << total << endl;
        }
        cout << (i+1) << ". " << total << endl;
        total = 0;
    }
    return 0;
}
