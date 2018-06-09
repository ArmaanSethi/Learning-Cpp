#include <iostream>

using namespace std;

class Time
{
public:
    Time();
    void setTime(int h, int m, int s, char a)
    {
        hour = h;
        min = m;
        sec = s;
        ampm = a;

    };
    int getHour()
    {
        return hour;
    }
    int military(int);
    void operator+(Time);
    void print();

private:
    int hour, min, sec, ampm;

};

Time :: Time()
{
    hour = 12;
    min = sec = ampm = 0;
}

int Time :: military(int hour)
{
    return (hour + 12);
}

void Time::operator+(Time day2)
{
    sec+=day2.sec;
    if(sec >= 60)
    {
        min+=1;
        sec-=60;
    }
    min+=day2.min;
    if(min >= 60)
    {
        hour+=1;
        min-=60;
    }
    hour+=day2.hour;
    if(hour>=12)
    {
        hour-=12;
    }
    print();
}

void Time :: print()
{
    // cout << "Military Time is : ";
    // if(ampm == 'p')
    //    hour = military(hour);
    cout << hour << ":" << min << ":" << sec << endl;
}

int main()
{
    Time day1, day2;
    int h1, m1, s1;
    char a1;
    h1 = day1.getHour();
    cout << h1 + 2 << endl;
    day1.print();
    cout << "Day 1" << endl;
    cout << "Hour: ";
    cin >> h1;
    cout << "Minute: ";
    cin >> m1;
    cout << "Second: ";
    cin >> s1;
    cout << "AM or PM(a or p): ";
    cin >> a1;
    day1.setTime(h1,m1,s1,a1);
    cout << "Day 2" << endl;
    cout << "Hour: ";
    cin >> h1;
    cout << "Minute: ";
    cin >> m1;
    cout << "Second: ";
    cin >> s1;
    cout << "AM or PM(a or p): ";
    cin >> a1;
    day2.setTime(h1,m1,s1,a1);
    cout << "Day 1" << endl;
    day1.print();
    cout << "Day 2" << endl;
    day2.print();
    cout << "Day 1 + Day 2" << endl;
    day1+day2;
    return 0;
}

