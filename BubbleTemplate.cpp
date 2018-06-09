#include "H:\My Documents\ComputerScience\Headers\MyClass.h"
#include<iostream>
#include<fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10000;

void input(int ia[], double da[], char ca[])
{
    for(int i = 0; i < N; i++)
    {
        ia[i] = rand() % 32001 + 0;
        da[i] = (double)((rand() % 10001) / (double)10000);
        ca[i] = char(rand() % 256 + 0);
    }
}

template<class type>
void output(type a[], ofstream &myfile)
{
        myfile << setprecision(4) << fixed;
        for(int i = 0; i < N; i++)
        {
            myfile << setw(8) << a[i];
            if((i + 1)% 10 == 0)
            {
                myfile << endl;
            }
        }
        myfile << endl;
}

int main()
{
    int intarray[N];
    double doubarray[N];
    char chararray[N];
    srand(time(0));
    input(intarray, doubarray, chararray);
    Bubble(intarray,N);
    Bubble(doubarray,N);
    Bubble(chararray,N);
    ofstream myfile;
    myfile.open("H://TestPotter.txt");
    output(intarray, myfile);
    output(doubarray, myfile);
    output(chararray, myfile);
    myfile.close();
}
