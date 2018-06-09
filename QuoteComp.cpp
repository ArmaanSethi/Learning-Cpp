#include <iostream>
#include<fstream>
#include <iomanip>

using namespace std;

const int N = 3;


class Quote
{
private:
    string first;
    string last;
    string q;
public:
    Quote();
    string getFirst()
    {
        return(first);
    }
    string getLast()
    {
        return(last);
    }
    string getQ()
    {
        return(q);
    }
    void set(string, string, string);
    void output();
    void operator=(Quote q2);
    int operator==(Quote q2);
    int operator>(Quote q2);

};

Quote::Quote()
{
    first = last = q = "";
}

void Quote::set(string l, string f, string qu)
{
    first = f;
    last = l;
    q = qu;
}

int Quote::operator>(Quote q2)
{
    if(last.compare(q2.last) > 0)
    {
        return 1;
    }else if(first.compare(q2.first) > 0)
    {
        return 1;
    }else if(q.compare(q2.q) > 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Quote::operator=(Quote q2)
{
    Quote temp;

    temp.last += last;//Temp = A
    temp.first += first;
    temp.q += q;

    last.erase(0, last.length());//A erase
    first.erase(0, first.length());
    q.erase(0, q.length());

    first += q2.first;//A = B
    last += q2.last;
    q += q2.q;

    q2.first.erase(0, q2.first.length());//B erase
    q2.last.erase(0, q2.last.length());
    q2.q.erase(0, q2.q.length());

    q2.first+=temp.first;//B = Temp
    q2.last+=temp.last;
    q2.q+=temp.q;

    temp.last.erase(0, temp.last.length());//Temp erase
    temp.first.erase(0, temp.first.length());
    temp.q.erase(0, temp.q.length());
}

void Quote::output()
{
    cout << "LAST:   " << last << endl;
    cout << "FIRST:  " << first << endl;
    cout << "QUOTE:  " << q << endl;
}

int main()
{
    Quote q[N];
    string lastname, firstname, quote;
    ifstream myfile("InQuote.txt");
    if (myfile.is_open())
    {
        while(myfile.good())
        {
            for(int i = 0; i < N; i++)
            {
                getline(myfile, lastname);
                getline(myfile, firstname);
                getline(myfile, quote);
                q[i].set(lastname, firstname, quote);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << "LAST:   " << q[i].getLast() << endl;
        cout << "FIRST:  " << q[i].getFirst() << endl;
        cout << "QUOTE:  " << q[i].getQ() << endl;
        cout << endl;
    }

    for(int i = 0; i < N ; i++)
        for(int j = 0; j < N - 1; j++)
            if((q[j] > q[j+1]) == 1)
                swap(q[j], q[j+1]);


    for(int i = 0; i < N; i++)
    {
        cout << "I =  " << i << endl;
        q[i].output();
        cout << endl;
    }
}
