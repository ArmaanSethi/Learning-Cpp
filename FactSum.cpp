#include <iostream>

using namespace std;


int main()
{
    int x,y,z, sum = 0, GCF = 0;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;

    for(int i = 1; i <= x; i++)
    {
        if(((x%i) == 0) && ((y%i)==0) && ((z%i)==0))
        {
            GCF = i;
            cout << GCF << ",";
            sum+=GCF;
        }
    }
    cout << endl << "FactorSum: " << sum << endl;
    return 0;
}
