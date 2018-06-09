#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


void input(double &p,double &r,int &n)
{
    cout << "Principle: ";
    cin >> p;
    cout << "Rate: ";
    cin >> r;
    cout << "How interest is compounded: ";
    cin >> n;
    cout << endl;
}

void output(double &p, double &r, int &n, double &a)
{
    for(int t = 1; t <=10; t++)
    {
        a = p* (pow((1 + ((r/100) / n)), (n*t)));
        cout << setw(25);
        std::cout << std::setprecision(2) << std::fixed;

        if(t == 10)
            cout << "Year " << t << ":  $" << a << endl;
        else
            cout << "Year " << t << ":   $" << a << endl;
    }

}

int main()
{
    double amount, principle, rate;
    int n;
    input(principle, rate, n);
    output(principle, rate, n, amount);
    return 0;
}
