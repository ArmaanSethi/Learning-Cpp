/*
*Armaan Sethi
*ACSL #2 Senior
*1/29/14
*Potter
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

void input(vector<char> &val, vector<char> &str, int &type)
{
    string inputS;
    string inputV;
    cin >> inputS;
    cin >> inputV;
    for(int i = 0; i < inputS.length()-1; i++)
    {
        str.push_back(inputS[i]);
   //     cout << str[i];
        if((str[i] == 'E')&&(type < 5))
            type = 5;
        else if((str[i] == '*')&&(type < 4))
            type = 4;
        else if((str[i] == '$') && (type < 3))
            type = 3;
        else if((str[i] == '.') && (type < 2))
            type = 2;
        else if((str[i] == ',') && (type < 1))
            type = 1;
    }
 //   cout << endl;
    for(int i = 0; i < inputV.length(); i++)
    {
        val.push_back(inputV[i]);
 //       cout << val[i];
    }
}

int main()
{
    for(int z = 0; z < 5; z++)
    {
        int type = 0;
        vector<char> value;
        vector<char> str;
        input(value, str, type);
       // cout << endl << type << endl;
        vector<char> result(str.size(), '*');
        if(type == 5)//E
        {
            result.resize(0);
            string temp;
            for(int i = 0; i < value.size(); i++)
                temp+=value[i];
            double num = 0, e = 0;
            istringstream(temp)>>num;
          //  cout << num << endl;
            if(num >= 1)
            {
                while(num>=10)
                {
                    num/=10.0;
                    e++;
                }
            }else
            {
                while(num<= 1)
                {
                    num*=10.0;
                    e--;
                }
            }
            cout << setprecision(str.size()-2) << fixed << num << "E";
            cout << setprecision(0) << fixed << e;
        }
        else if(type == 4)// *
        {
            int beforeDecimalv=0, afterDecimalv=0, afterDecimals=0, beforeDecimals=0;
            for(int i = 0; i < str.size(); i++)
                if(str[i] == '.')
                    beforeDecimals = i;

            for(int i = 0; i < value.size(); i++)
                if(value[i] == '.')
                    beforeDecimalv = i;

            afterDecimals = str.size()-beforeDecimals-1;
            afterDecimalv = value.size()-beforeDecimalv-1;
           // cout << "ADS: " << afterDecimals << " ADV: " << afterDecimalv << endl;
            if(afterDecimals < afterDecimalv)
            {
                result.resize(0);
                if(value[beforeDecimalv+afterDecimals+1] >= '5')
                {
                    if(value[beforeDecimalv+afterDecimals+1] == '9')
                    {
                        int a = 1;
                        while(value[beforeDecimalv+afterDecimals+a] == '9')
                        {
                            value[beforeDecimalv+afterDecimals+a] = '0';
                            a--;
                        }
                        if(value[beforeDecimalv+afterDecimals+a] == '.')
                        {
                            value[beforeDecimalv+afterDecimals+a-1] += 1;
                        }
                        else
                        {
                            value[beforeDecimalv+afterDecimals+a] += 1;
                        }
                        //value[beforeDecimalv+afterDecimals+a] += 1;
                    }
                    else
                    {
                        value[beforeDecimalv+afterDecimals] += 1;
                    }
                }
                for(int i = (afterDecimalv-afterDecimals)+1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                result.push_back('$');
                for(int i = 0; i < (beforeDecimals-beforeDecimalv)-2; i++)
                    result.push_back('*');
                reverse(result.begin(), result.end());
            }
            else if(afterDecimals > afterDecimalv)
            {
                result.resize(0);
                for(int i = 0; i < (afterDecimals-afterDecimalv); i++)
                    result.push_back('0');
                for(int i = 1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                result.push_back('$');
                for(int i = 0; i < (beforeDecimals-beforeDecimalv)-2; i++)
                    result.push_back('*');
                reverse(result.begin(), result.end());
            }
            else
            {
                result.resize(result.size()-1);
                for(int i = 1; i < value.size()+1; i++)
                    swap(result[result.size()-i], value[value.size()-i]);
            }
            result[result.size()-value.size()-1] = '$';
        }
        else if(type == 3)   //$
        {
            int beforeDecimalv=0, afterDecimalv=0, afterDecimals=0, beforeDecimals=0;
            for(int i = 0; i < str.size(); i++)
                if(str[i] == '.')
                    beforeDecimals = i;

            for(int i = 0; i < value.size(); i++)
                if(value[i] == '.')
                    beforeDecimalv = i;

            afterDecimals = str.size()-beforeDecimals-1;
            afterDecimalv = value.size()-beforeDecimalv-1;
         //   cout << "ADS: " << afterDecimals << " ADV: " << afterDecimalv << endl;
            if(afterDecimals < afterDecimalv)
            {
                result.resize(0);
                if(value[beforeDecimalv+afterDecimals+1] >= '5')
                {
                    if(value[beforeDecimalv+afterDecimals+1] == '9')
                    {
                        int a = 1;
                        while(value[beforeDecimalv+afterDecimals+a] == '9')
                        {
                            value[beforeDecimalv+afterDecimals+a] = '0';
                            a--;
                        }
                        if(value[beforeDecimalv+afterDecimals+a] == '.')
                        {
                            value[beforeDecimalv+afterDecimals+a-1] += 1;
                        }
                        else
                        {
                            value[beforeDecimalv+afterDecimals+a] += 1;
                        }
                        //value[beforeDecimalv+afterDecimals+a] += 1;
                    }
                    else
                    {
                        value[beforeDecimalv+afterDecimals] += 1;
                    }
                }
                for(int i = (afterDecimalv-afterDecimals)+1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                result.push_back('$');
                reverse(result.begin(), result.end());
            }
            else if(afterDecimals > afterDecimalv)
            {
                result.resize(0);
                for(int i = 0; i < (afterDecimals-afterDecimalv); i++)
                    result.push_back('0');
                for(int i = 1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                result.push_back('$');
                reverse(result.begin(), result.end());
            }
            else
            {
                result.resize(0);
                result.push_back('$');
                for(int i = 0; i < value.size(); i++)
                    result.push_back(value[i]);
            }
        }
        else if(type == 2)      //.
        {
            int beforeDecimalv=0, afterDecimalv=0, afterDecimals=0, beforeDecimals=0;
            for(int i = 0; i < str.size(); i++)
                if(str[i] == '.')
                    beforeDecimals = i;

            for(int i = 0; i < value.size(); i++)
                if(value[i] == '.')
                    beforeDecimalv = i;

            afterDecimals = str.size()-beforeDecimals-1;
            afterDecimalv = value.size()-beforeDecimalv-1;
        //    cout << "ADS: " << afterDecimals << " ADV: " << afterDecimalv << endl;
            if(afterDecimals < afterDecimalv)
            {
                result.resize(0);
                if(value[beforeDecimalv+afterDecimals+1] >= '5')
                {
                    if(value[beforeDecimalv+afterDecimals+1] == '9')
                    {
                        int a = 1;
                        while(value[beforeDecimalv+afterDecimals+a] == '9')
                        {
                            value[beforeDecimalv+afterDecimals+a] = '0';
                            a--;
                        }
                        if(value[beforeDecimalv+afterDecimals+a] == '.')
                        {
                            value[beforeDecimalv+afterDecimals+a-1] += 1;
                        }
                        else
                        {
                            value[beforeDecimalv+afterDecimals+a] += 1;
                        }
                        //value[beforeDecimalv+afterDecimals+a] += 1;
                    }
                    else
                    {
                        value[beforeDecimalv+afterDecimals] += 1;
                    }
                }
                for(int i = (afterDecimalv-afterDecimals)+1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                for(int i = 0; i < (beforeDecimals-beforeDecimalv); i++)
                    result.push_back('*');
                reverse(result.begin(), result.end());
            }
            else if(afterDecimals > afterDecimalv)
            {
                result.resize(0);
                for(int i = 0; i < (afterDecimals-afterDecimalv); i++)
                    result.push_back('0');
                for(int i = 1; i < value.size()+1; i++)
                    result.push_back(value[value.size()-i]);
                for(int i = 0; i < (beforeDecimals-beforeDecimalv); i++)
                    result.push_back('*');
                reverse(result.begin(), result.end());
            }
            else
            {
                for(int i = 1; i < value.size()+1; i++)
                    swap(result[result.size()-i], value[value.size()-i]);
            }
        }
        else if(type == 1)      //,
        {
            result.resize(0);
            for(int i = 1; i < str.size(); i++)
            {
                if(i < value.size()+1)
                {
                    result.push_back(value[value.size()-i]);
                    if(((i%3)==0))
                    {
                        result.push_back(',');
                    }
                }
                else
                {
                    result.push_back('*');
                }
            }
            reverse(result.begin(), result.end());
        }
        else
        {
            for(int i = 1; i < value.size()+1; i++)
                swap(result[result.size()-i], value[value.size()-i]);
        }

        for(int i = 0; i < result.size(); i++)
            cout << result[i];
        cout << endl;
    }
    return 0;
}
