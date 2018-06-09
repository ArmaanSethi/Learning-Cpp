#include<iostream>
#include<string>
#include<fstream>
#include<math.h>

using namespace std;

void extraction(string &f, int &a, int &b, int &c)
{
    ifstream myfile("Quadratic.txt");
    if (myfile.is_open())
    {
        while(myfile.good())
        {
            getline(myfile, f);
        }
    }

    myfile.close();
    cout << f << endl;
    a = (f[0] - '0');
    b = (f[4] - '0');
    c = (f[7] - '0');
    if(f[3] == '-')
        b *= -1;
    if(f[6] == '-')
        c *= -1;
}


void quadratic(int &a, int &b, int &c, int &inside, int &outside)
{
    inside = ((b * b) - ((4)*(a)*(c)));
    cout << "INSIDE: " << inside << endl << endl << endl;
    if(inside < 0)
    {
        inside*=-1;
    }
    int root = sqrt(inside);
    outside = 1;
    for(int i = root; i > 1; i--)
    {
        if ( (inside % i) == 0)
        {
            if(inside % (i * i) == 0)
            {
                inside = (inside/(i*i));
                outside = i;
            }
        }
    }


}

void output(int &a, int &b, int &c, int &inside, int &outside)
{
    cout << a << "  " << b << "   " << c << endl;
    a = 2 * a;
    int GCF = 0;
    for(int i = 1; i <= outside; i++)
    {
        if((b % i ==0) && (outside % i == 0) && (a % i == 0))
        {
            GCF = i;
        }
    }
    cout << "GCF: " << GCF << endl;
    a /= GCF;
    b /= GCF;
    outside /= GCF;

    if(((b * b) - ((4)*(a / 2)*(c))) < 0)
    {
        if (inside == 1)
        {
            if(outside == 1)
            {
                cout << "(" << (b*-1) + outside <<  "i) " << "/" << (a) << endl;
                cout << "(" << (b*-1) - outside <<  "i) " << "/" << (a) << endl;
            }
            else
            {
                cout << "(" << (b*-1) + outside <<  "i) " << "/" << (a) << endl;
                cout << "(" << (b*-1) - outside <<  "i) " << "/" << (a) << endl;
            }
        }
        else
        {
            if(outside == 1)
            {
                cout << "(" << (b*-1) << "+" <<  "i{" << inside << " ) " << "/" << (a) << endl;
                cout << "(" << (b*-1) << "-" <<  "i{" << inside << " ) " << "/" << (a) << endl;
            }
            else
            {
                cout << "(" << (b*-1) << "+" << outside << "i{" << inside << " ) " << "/" << (a) << endl;
                cout << "(" << (b*-1) << "-" << outside << "i{" << inside << " ) " << "/" << (a) << endl;
            }
        }
    }
    else
    {
        if(inside == 0)
        {
            cout << "(" << (b*-1) << "/" << (a) << endl;
            cout << "(" << (b*-1) << "/" << (a) << endl;
        }
        if (inside == 1)
        {
            cout << "(" << (b*-1) + outside <<  ") " << "/" << (a) << endl;
            cout << "(" << (b*-1) - outside <<  ") " << "/" << (a) << endl;
        }
        else
        {
            cout << "(" << (b*-1) << "+" << outside << "{" << inside << " ) " << "/" << (a) << endl;
            cout << "(" << (b*-1) << "-" << outside << "{" << inside << " ) " << "/" << (a) << endl;
        }
    }

}

int main()
{
    string formula;
    int a, b, c, inside, outside;//A, B, and C value of Ax2+Bx+C|| Inside = Inside of the root, Outside = Outside of the root.

    extraction(formula,a , b, c);
    cout << a << b << c << endl;
    quadratic(a, b, c, inside, outside);
    output(a, b, c, inside, outside);
}
