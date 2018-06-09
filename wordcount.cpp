#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void input(vector<string> &g)
{
    ifstream file("wordcount.txt");
    if(file.is_open())
    {
        int i = 0;
        while(file.good())
        {
            string line;
            getline(file, line);
            g.push_back(line);
            cout << g[i] << endl;
            line.erase(line.length());
            i++;
        }
        file.close();
    }
    else
    {
        cout << "It is not open!!" << endl;
    }
}

void process(vector<string> &g, string &phrase, int &number)
{
    int count[g.size()];
    for(int i = 0; i < g.size(); i++) count[i] = 1;
    for(int i = 0; i < g.size(); i++)
    {
        for(int a = 0; a < g[i].length(); a++)
            if(g[i][a] == ' ')
                count[i]++;

        if(count[i] > number)
        {
            number = count[i];
            phrase.erase(0, phrase.length());
            phrase += g[i];
        }
    }
//    for(int i = 0; i < g.size(); i++) cout << "Words " << i + 1 << ": " << count[i] << endl;

//    cout << number << "    : :    " << phrase;
}

void output(vector<string> &g)
{

}

int main()
{
    vector<string> sentence;
    string phrase;
    int number = 0;
//    ifstream file("S:/public/cs/fvfile.txt");
    ifstream file("wordcount.txt");
    ofstream outfile("outfile.txt");
    input(sentence);
    process(sentence, phrase, number);
    output(sentence);
    outfile.close();
    return 0;
}
