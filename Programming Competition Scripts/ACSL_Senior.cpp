#include <iostream>
#include <iomanip>


using namespace std;

const int PEOPLE = 5;
const int DAYS = 7;


void input(int location[], char start_time[][DAYS],char end_time[][DAYS])
{
    for (int i = 0; i < PEOPLE; i++)
    {
        cout << "Person " << i + 1 << endl;
        cin >> location[i];
        for(int a = 0; a < DAYS; a++ )
        {
            cin >> start_time[i][a];
            cin >> end_time[i][a];
        }
        cout << endl;
    }
}

void output(double pay[])
{
    double total[PEOPLE];

    for (int i = 0; i < PEOPLE; i++)
    {
        for(int a = 0; a < DAYS; a++)
        {
            cout << setprecision(2);
            cout.setf( ios :: showpoint | ios :: fixed);
        }
    }
    for (int i = 0; i < PEOPLE; i++)
    {
        cout << "$" << pay[i] << endl;
    }
}

double find_hours(char start_time, char end_time)
{
    double num_start_time, num_end_time;

    if (start_time >= 'A' && start_time <= 'H')
        num_start_time = (start_time - 'A') + 10;
    else
        num_start_time = (start_time - '0');

    if (end_time >= 'A' && end_time <= 'H')
        num_end_time = (end_time - 'A') + 10;
    else
        num_end_time = (end_time - '0');

    return  ((num_end_time - num_start_time)/2);
}

int find_pay(int location[],char start_time[][DAYS],char end_time[][DAYS], double pay[])
{
    for (int i = 0; i < PEOPLE; i++)
    {
        pay[i] = 0;
        double hours = 0;
        for(int b = 0; b < DAYS; b++)
        {
            hours+= find_hours(start_time[i][b], end_time[i][b]);
        }

        for(int a = 0; a < DAYS; a++)
        {
            if(location[i] >=100 && location[i] <= 199)
            {
                if(hours < 30)
                    pay[i] = hours * 10;
                else
                    pay[i] = (10 * 30) + ((hours - 30) * 15);
            }
            else if(location[i] >= 200 && location [i] <= 299)
            {
                if(hours < 40)
                    pay[i] = hours * 7.5;
                else
                    pay[i] = (7.5 * 40) + ((hours - 40) * 15);
            }
            else if(location[i] >= 300 && location[i] <= 399)
            {
                if(hours < 20)
                    pay[i] = hours * 9.25;
                else
                    pay[i] = (9.25 * 20) + ((hours - 20) * 10.5);
            }
            else if(location[i] >= 400 && location[i] <= 499)
            {
                if(a == 1 || a == 7)
                    pay[i] += find_hours(start_time[i][a], end_time[i][a]) * 13.5;
                else
                    pay[i] += find_hours(start_time[i][a], end_time[i][a]) * 6.75;
            }
            else if(location[i] >= 500 && location[i] <= 599)
            {
                if(find_hours(start_time[i][a], end_time[i][a]) < 6)
                    pay[i] += find_hours(start_time[i][a], end_time[i][a]) * 8;
                else
                    pay[i] += (8 * 6) + ((find_hours(start_time[i][a], end_time[i][a]) - 6) * 12);
            }
        }
    }
}

int main()
{
    int location[PEOPLE];
    char start_time[PEOPLE][DAYS], end_time[PEOPLE][DAYS];
    double  pay[PEOPLE];

    input(location, start_time, end_time);
    find_pay(location, start_time, end_time, pay);
    output(pay);

    return 0;
}
