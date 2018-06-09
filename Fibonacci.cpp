#include <iostream>

using namespace std;


void input(int &s1,int &s2,int &t)
{
    cout << "First Term: ";
    cin >> s1;
    cout << "Second Term: ";
    cin >> s2;
    cout << "Find Term: ";
    cin >> t;
}

void output(int &s1,int &s2,int &t)
{
    int sum = 0;
    if(t == 1)
    {
        cout << s1;
    }
    else if (t == 2)
    {
        cout << s2;
    }
    else
    {
        for(int i = 0; i < (t - 2); i++)
        {
            sum = s1 + s2;
            s1 = s2;
            s2 = sum;
        }
        cout << sum;
    }
}

int main()
{
    int seed1, seed2, term;

    input(seed1, seed2, term);
    output(seed1, seed2, term);

    return 0;
}
