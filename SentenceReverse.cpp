#include<iostream>
#include<string>
#include<vector>

using namespace std;

void input(string &s)
{
    cout << "Sentence: ";
    getline(cin, s);
}

void reverse(string &s)
{
    string s2;
    for(int i = (s.length() - 1); i >= 0; i--)
    {
        s2 += s[i];
    }
    swap(s, s2);
}

void extraction(string &str)
{

    int x = 0;
    cout << str.find(' ') << endl;

    string s = str;
    string s2;
    string s3;

    s.erase((s.length() - 1), 1);
    while( x <= s.length())
    {
        x = s.find(' ');
        s2 += s.substr(0,x);
        reverse(s2);
        s3 += s2 + " ";
        s.erase(0,x + 1);
        s2.erase(0,s2.length());
    }
    s3.erase(str.length() - 1, 1);
    s3 += str.substr(str.length() - 1, 1);
    swap(s3, str);
}

void output(string &s)
{
    cout << s << endl;
}

int main()
{
    string sentence;
    input(sentence);
    extraction(sentence);
    output(sentence);
}
