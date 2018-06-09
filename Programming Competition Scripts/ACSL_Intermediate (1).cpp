#include <iostream>
#include <iomanip>


using namespace std;

const int PEOPLE = 5;
const int DAYS = 2;


void input(int location[][DAYS],int day[][DAYS], char start_time[][DAYS],char end_time[][DAYS])
{
    for (int i = 0; i < PEOPLE; i++)
    {
        cout << "Person " << i + 1 << endl;
        for(int a = 0; a < DAYS; a++ )
        {
            cin >> location[i][a];
            cin >> day[i][a];
            cin >> start_time[i][a];
            cin >> end_time[i][a];
            cout << endl;
        }
        cout << endl;
    }
}

void output(double pay[][DAYS])
{
    double total[PEOPLE];

    for (int i = 0; i < PEOPLE; i++)
    {
        total[i]=0;
        for(int a = 0; a < DAYS; a++)
        {
            total[i] += pay[i][a];
            cout << setprecision(2);
            cout.setf( ios :: showpoint | ios :: fixed);
        }
    }
    for (int i = 0; i < PEOPLE; i++)
    {
        cout << "$" << total[i] << endl;
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

int find_pay(int location[][DAYS],char start_time[][DAYS],char end_time[][DAYS], double pay[][DAYS], int day[][DAYS])
{
    for (int i = 0; i < PEOPLE; i++)
    {
        for(int a = 0; a < DAYS; a++)
        {
            double hours = find_hours(start_time[i][a], end_time[i][a]);

            if(location[i][a] >=100 && location[i][a] <= 199)
            {
                if(hours < 5)
                    pay[i][a] = hours * 10;
                else
                    pay[i][a] = (10 * 5) + ((hours - 5) * 15);
            }
            else if(location[i][a] >= 200 && location [i][a] <= 299)
            {
                if(hours < 6)
                    pay[i][a] = hours * 7.5;
                else
                    pay[i][a] = (7.5 * 6) + ((hours - 6) * 15);
            }
            else if(location[i][a] >= 300 && location[i][a] <= 399)
            {
                if(hours < 4)
                    pay[i][a] = hours * 9.25;
                else
                    pay[i][a] = (9.25 * 4) + ((hours - 4) * 10.5);
            }
            else if(location[i][a] >= 400 && location[i][a] <= 499)
            {
                if(day[i][a] == 1 || day[i][a] == 7)
                    pay[i][a] = hours * 13.5;
                else
                    pay[i][a] = hours * 6.75;
            }
            else if(location[i][a] >= 500 && location[i][a] <= 599)
            {
                if(hours < 6)
                    pay[i][a] = hours * 8;
                else
                    pay[i][a] = (8 * 6) + ((hours - 6) * 12);
            }
        }
    }
}

int main()
{
    int location[PEOPLE][DAYS], day[PEOPLE][DAYS];
    char start_time[PEOPLE][DAYS], end_time[PEOPLE][DAYS];
    double  pay[PEOPLE][DAYS];

    input(location, day, start_time, end_time);
    find_pay(location, start_time, end_time, pay, day);
    output(pay);

    return 0;
}
