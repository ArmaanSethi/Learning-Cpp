#include <iostream>

using namespace std;


void input(double &b,int &x)
{
    cout << "Base:  ";
    cin >> b;
    cout << "Exponent: ";
    cin >> x;
}

void output(double b, int x)
{
    if (x == 0 && b != 0)
    {
        cout << "1" << endl;
    }
    else if(b == 0 && x == 0)
    {
        cout << "Indeterminate Form" << endl;
    }
    else if(b == 0 && x < 0)
    {
        cout << "UNDEFINED" << endl;
    }
    else if(x > 0)
    {
        double product = 1;
        for(int i = 0; i < (x); i++)
        {
            product = product * b;
        }
        cout << product << endl;
    }
    else if(x < 0)
    {
        double product = 1;
        for(int i = 0; i > (x); i--)
        {
            product = product * b;
        }
        product = (1/product);
        cout << product << endl;
    }
}

int main()
{
    double b;
    int x;
    input(b,x);
    output(b,x);
}
