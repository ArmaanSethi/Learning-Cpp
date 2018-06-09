/*Armaan Sethi
**12/20/13
**Contest #1 - Sen 5
**ENLOE HS - POTTER
*/
#include<iostream>

using namespace std;

int score(int point[], int pos, char dir) {
    int multiplier = 1, sum = 0;
    for(int i= 0; i < 4; i++) {
        sum += point[i];
        if((pos % 6) == 3)
            sum += point[i];
        else if((pos % 5) == 0)
            sum += (point[i] * 2);
        else if((pos % 7) == 0)
            multiplier *= 2;
        else if((pos % 8) == 0)
            multiplier *= 3;
        if(dir == 'H') pos++;
        if(dir == 'V') pos+=10;
    }
    return (sum * multiplier);
}

int main() {
    char letter, direction[3];
    int position[3], point[4], total;
    for(int i = 0; i < 4; i++) {
        cin >> letter;
        if((letter == 'A') || (letter == 'E')) point[i] = 1;
        if((letter == 'D') || (letter == 'R')) point[i] = 2;
        if((letter == 'B') || (letter == 'M')) point[i] = 3;
        if((letter == 'V') || (letter == 'Y')) point[i] = 4;
        if((letter == 'J') || (letter == 'X')) point[i] = 8;
    }
    for(int i = 0; i < 5; i++) {
        total = 0;
        for(int j = 0; j < 3; j++) {
            cin >> position[j];
            cin >> direction[j];
        }
        for(int j = 0; j < 3; j++) {
            if((score(point, position[j], direction[j])) > total) {
                total = (score(point, position[j], direction[j]));
            }
        }
        cout << "Output: " << total << endl;
    }
    return 0;
}
