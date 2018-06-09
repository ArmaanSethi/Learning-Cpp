#include <iostream>
#include <iomanip>


using namespace std;

const int PEOPLE = 4;



void input(int location[],char start_time[],char end_time[])
{
    for(int i = 0; i < PEOPLE; i++ )
    {
        cout << "Person " << i + 1 << endl;
        cout << "Location : ";
        cin >> location[i];
        cout << "Start Time : ";
        cin >> start_time[i];
        cout << "End Time : ";
        cin >> end_time[i];
    }
    cout << endl;
}

void output(double pay[])
{
    double sum = 0;
    for(int i = 0; i < PEOPLE; i++)
    {
        sum += pay[i];
        cout << setprecision(2);
        cout.setf( ios :: showpoint | ios :: fixed);
        cout << "$" << pay[i] << endl;
    }
    cout << "$" << sum;
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

int calculate(int location[],char start_time[],char end_time[], double pay[])
{
    for(int i = 0; i < PEOPLE; i++)
    {
        double hours = find_hours(start_time[i], end_time[i]);

        if(location[i] >=0 && location[i] <= 9)
            pay[i] = hours * 10;
        else if(location[i] >= 10 && location [i] <= 19)
        {
            if(hours < 4)
                pay[i] = hours * 8;
            else
                pay[i] = (4 * 8) + ((hours - 4) * 12);
        }
        else if(location[i] >= 20 && location[i] <= 29)
        {
            if(hours < 4)
                pay[i] = hours * 12;
            else
                pay[i] = (12 * 4) + ((hours - 4) * 12 * 2);
        }
    }
}

int main()
{
    int location[PEOPLE];
    char start_time[PEOPLE], end_time[PEOPLE];
    double  pay[PEOPLE + 1];

    input(location, start_time, end_time);
    calculate(location, start_time, end_time, pay);
    output(pay);

    return 0;
}
