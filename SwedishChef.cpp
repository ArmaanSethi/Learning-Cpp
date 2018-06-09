#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int N = 5;

class Swedish {
private:
    string phrase;
    string swedPhrase;
public:
    Swedish();
    string getPhrase() {
        return(phrase);
    }
    string getTranslate() {
        return(swedPhrase);
    }
    void setPhrase(string p);
    void setSwed(string s);
    void translate();
    void print();
};

Swedish::Swedish() {
    phrase = "";
    swedPhrase = "";
}

void Swedish::setPhrase(string p) {
    phrase = p;
}

void Swedish::setSwed(string s) {
    swedPhrase = s;
}

void Swedish::print() {
    cout << "Phrase:  " << getPhrase() << endl;
    cout << "Swedish: " << getTranslate() << endl;
}

void Swedish::translate() {
    swedPhrase = phrase + " ";
    int i = 0;
    int FirstOccuranceOfI = 1;
    while(i < swedPhrase.length()) {
        if(swedPhrase[i] == '.') {
            swedPhrase += "Bork, Bork, Bork!";
        } else if ((i < swedPhrase.length() - 2) && (swedPhrase[i] == 'T' &&  swedPhrase[i+1] == 'H' && swedPhrase[i+2] == 'E')) {
            swedPhrase = swedPhrase.substr(0,i) + "ZEE" + swedPhrase.substr(i+3, (swedPhrase.length() - 3));
            i+=2;
        } else if(swedPhrase[i] == 'A') {
            if(swedPhrase[i+1] == 'N') {
                swedPhrase = swedPhrase.substr(0,i) + "UN" + swedPhrase.substr(i+2, (swedPhrase.length() - 3));
                i++;
            } else if(swedPhrase[i+1] == 'U') {
                swedPhrase = swedPhrase.substr(0,i) + "OO" + swedPhrase.substr(i+2, swedPhrase.length()-2);
                i++;
            } else if(swedPhrase[i+1] != ' ') {
                swedPhrase[i] = 'E';
            }
        } else if(swedPhrase[i] == 'O') {
            if (swedPhrase[i+1] == 'W') {
                swedPhrase = swedPhrase.substr(0,i) + "OO" + swedPhrase.substr(i+2, swedPhrase.length() - 2);
                i++;
            } else {
                swedPhrase[i] = 'U';
            }
        } else if ((swedPhrase[i] == 'I') && (((FirstOccuranceOfI == 1) && (i!=0) && (swedPhrase[i-1] != ' ')))) {
            swedPhrase = swedPhrase.substr(0,i) + "EE" + swedPhrase.substr(i+1, swedPhrase.length() -1 );
            i++;
            FirstOccuranceOfI = 0;
        } else  if(swedPhrase[i] == 'E') {
            if((swedPhrase[i+1] == 'N') && (swedPhrase[i+2] == ' ' ||swedPhrase[i+2] == '.' ||swedPhrase[i+2] == '?' ||swedPhrase[i+2] == '!')) {
                swedPhrase = swedPhrase.substr(0,i) + "EE" + swedPhrase.substr(i+2, swedPhrase.length() - 2);
                i++;
            } else if((swedPhrase[i+1] == ' ') ||(swedPhrase[i+1] == '.') || (swedPhrase[i+1] == '!') || (swedPhrase[i+1] == '?')) {
                swedPhrase = swedPhrase.substr(0,i) + "E-A" + swedPhrase.substr(i+1, swedPhrase.length() - 3);
                i+=2;
            } else if((i == 0) || (swedPhrase[i-1] == ' ')) {
                swedPhrase[i] = 'I';
            }
        } else if(swedPhrase[i] == 'U') {
            swedPhrase = swedPhrase.substr(0,i) + "OO" + swedPhrase.substr(i+1, swedPhrase.length() - 2);
            i++;
        }
        if(swedPhrase[i] == ' ') {
            FirstOccuranceOfI = 1;
        }
        i++;
    }
    //for(int i = 0; i < swedPhrase.length(); i++)
    //    if((int(swedPhrase[i] > 96)))
    //        swedPhrase[i] -= 32;

}

int main() {
    Swedish s[N];
    string inphrase;
    ifstream myfile("SwedishChef.txt");
    if (myfile.is_open()) {
        for(int i = 0; i < N; i++) {
            getline(myfile, inphrase);
            s[i].setPhrase(inphrase);
        }
    }
    myfile.close();
    for(int i = 0; i < N; i++) {
        s[i].translate();
        s[i].print();
    }
}
