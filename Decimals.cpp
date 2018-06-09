#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &v, int &a, int &b)
{
    cout << "A: " ;
    cin >> a;
    cout << "B: ";
    cin >> b;
}

void seperate(vector<int> &v, int &a, int &b)
{
    double AB = (double)a/b;
    int counter[10], posistion[10];
    for(int i = 0; i < 10; i++)
    {
        counter[i] = 0;
        posistion[i] = 0;
    }
    int Z,x = 1, i = 0;
    do
    {
        if(AB >= 10) AB = AB / 10;
        Z = AB * x;
        v.resize(v.size() + 1);
        v[i] = Z % 10;
        x = 10 * x;
        counter[(Z % 10) - 1]++;
        if(posistion[(Z % 10)] == 0)
            posistion[(Z % 10)] = i;
        i++;
    }
    while(counter[(Z % 10) - 1] < 2);

    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0)
            cout << v[i];
        else
            cout << v[i];
    }
    cout << endl << "Posistion: " << posistion[Z % 10];
}

int main()
{
    vector<int> vector1;
    int A, B;
    input(vector1, A, B);
    seperate(vector1, A, B);
    return 0;
}
