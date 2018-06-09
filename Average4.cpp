#include <iostream>
#include <iomanip>

using namespace std;


void input(double &sum, int &nG)
{

    double grade;


    sum = 0;
    cout << "(Type in A NEGATiVE NUMBER if you have no more grades to add)" << endl;
    cout << endl;

    nG = 0;

    do
    {
        int nG2 = nG + 1;
        int nG3 = nG2 % 100;
        int nG4 = nG2 % 10;

        if ( nG3 == 11 || nG3 == 12 || nG3 == 13)
        {
            cout << "Your  " << nG2 << "th grade : " << endl;
            cin >> grade;
        }
        else if ( nG4 == 1)
        {
            cout << "Your  " << nG2 << "st grade : " << endl;
            cin >> grade;
        }
        else if ( nG4 == 2)
        {
            cout << "Your  " << nG2 << "nd grade : " << endl;
            cin >> grade;
        }
        else if (nG4 == 3)
        {
            cout << "Your  " << nG2 << "rd grade : " << endl;
            cin >> grade;
        }
        else
        {
            cout << "Your  " << nG2 << "th grade : " << endl;
            cin >> grade;
        }




        if (grade >= 0)
        {

            sum = sum + grade;
            cout << endl;
            nG++;
        }

    }
    while ( grade >= 0);
}

double calculate (double s, double nG)
{

    return (s) / (nG) ;

}

char letterGrade(double average)
{

    if(average >= 93)
    {
        return 'A';
    }

    else if(average >= 85)
    {
        return 'B';
    }

    else if(average >= 76)
    {
        return 'C';
    }

    else if(average >= 70)
    {
        return 'D';
    }

    else
    {
        return 'F';
    }

}

void output(double a, char lG)
{

    cout << setprecision(2);
    cout.setf( ios :: showpoint | ios :: fixed);

    cout << "Your average is " << a << endl;
    cout << "Your letter grade is " << lG << endl;

}

int main()
{

    int numGrades;
    double sum, average;
    char letter;

    input(sum, numGrades);

    average = calculate ( sum, numGrades);
    letter = letterGrade(average);

    output ( average, letter);

    return 0;
}
