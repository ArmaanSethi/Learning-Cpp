#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    string inputS;
    string inputV;
    vector<char> value;
    vector<char> string;
    int type = 0;
    cin >> inputS;
    cin >> inputV;
    for(int i = 0; i < inputS.length()-1; i++)
    {
        string.push_back(inputS[i]);
        cout << string[i];
        if((string[i] == '$') && (type < 3))
            type = 3;
        else if((string[i] == '.') && (type < 2))
            type = 2;
        else if((string[i] == ',') && (type < 1))
            type = 1;
    }
    cout << endl;
    for(int i = 0; i < inputV.length(); i++)
    {
        value.push_back(inputV[i]);
        cout << value[i];
    }
    cout << endl << type << endl;
    vector<char> result(string.size(), '*');
    if(type == 3)//$
    {

    }else if(type == 2)//,
    {

    }else if(type == 1)//.
    {

    }else{
        for(int i = 1; i < value.size()+1; i++)
        {
            swap(result[result.size()-i], value[value.size()-i]);
        }
    }
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }

    return 0;
}
