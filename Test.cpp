#include "H:\My Documents\ComputerScience\Headers\MyClass.h"
#include <iostream>
#include <fstream>
#include <iomanip>

const int N =  10;

class ThreeDPoint {
private:
    int x,y,z;
public:
    ThreeDPoint();
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    void set(int xVal, int yVal, int zVal);
    void operator=(ThreeDPoint p2);
    int operator>(ThreeDPoint p2);
};

ThreeDPoint::ThreeDPoint() {
    x = y = z = 0;
}

void ThreeDPoint::set(int xVal, int yVal, int zVal)
{
    x = xVal;
    y = yVal;
    z = zVal;
}

void ThreeDPoint::operator=(ThreeDPoint p2) {
    x = p2.x;
    y = p2.y;
    z = p2.z;
}

int ThreeDPoint::operator>(ThreeDPoint p2) {
    if(x > p2.getX()) {
        return 1;
    } else if(x < p2.getX()) {
        return 0;
    } else {
        if(y < p2.getY()) {
            return 1;
        } else if(y > p2.getY()) {
            return 0;
        } else {
            if(z > p2.getZ()) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    ThreeDPoint p[N];
    //string lastname, firstname, quote;
    int a,b,c;
    char random;
    ifstream myfile;
    myfile.open("MyFile.txt");
    //ifstream myfile("S://Public/CS/threeD.txt");
    //ifstream myfile;
    cout<<myfile<<endl;
    //if (myfile.is_open()) {
        //cout << "CHICKEN: " <<endl;

            for(int i = 0; i < 10; i++) {
                myfile >> random;
                myfile >> a;
                myfile >> random;
                myfile >> b;
                myfile >> random;
                myfile >> c;
                myfile >> random;
                cout << "A: " << a << "  B: " << b << "  C: " << c << endl;
                //getline(myfile, lastname, ',');
                //getline(myfile, firstname, ',');
                //getline(myfile, quote);
                p[i].set(a, b, c);

            }
        //}
    myfile.close();

    Bubble(p,N);

    ofstream outfile;
    outfile.open("H://TestPotter.txt");
    for(int i = 0; i < N; i++) {
        cout << "(";
        cout <<  p[i].getX() << ",";
        cout <<  p[i].getY() << ",";
        cout <<  p[i].getZ() << ")" << endl;
    }
    outfile.close();
}

