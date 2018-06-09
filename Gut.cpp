#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<windows.h>

using namespace std;

class Card {
private:
    int value;
    int suit;
public:
    Card() {
        value = suit = 0;
    }
    int getValue() {
        return value;
    }
    int getSuit() {
        return suit;
    }
    void set(int v, int s) {
        value = v;
        suit = s;
    }
    void display();
};

class Game {
private:
    vector<Card> deck;
    vector<Card> player1;
    vector<Card> player2;
    vector<Card> player3;
    int status, winner, hand;//Turn, Number of Cards,Who wins
    void playCard();
    void pass();//push to hand, pop from deck
public:
    Game();//Get Cards, Shuffle Cards, Deal Twice, Discard
    void execute();
    void display();
};

Game :: Game() {
    status = winner = 0;
    deck.resize(6);

    // for(int i = 0; i < 52; i++)
    //    deck[i].set((i%13)+1, (i/13)+1);

    //random_shuffle(deck.begin(),deck.end());

    int a[6] = {13,49,30,18,46,42};
    for(int i = 0; i < 6; i++) {
        deck[i].set(((a[i]%13)+1), ((a[i]/13)+1));
        deck[i].display();
        cout << endl;
    }
    player1.push_back(deck[0]);
    player1.push_back(deck[1]);
    player2.push_back(deck[2]);
    player2.push_back(deck[3]);
    player3.push_back(deck[4]);
    player3.push_back(deck[5]);

    /*for(int i = 0; i < 7; i++) {
        player1.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
    for(int i = 0; i < 7; i++) {
        player2.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
    //    pile = deck[deck.size()-1];
    deck.pop_back();*/
}

void Card::display() {
    if(value == 1)
        cout << 'A';
    else if(value == 11)
        cout << 'J';
    else if(value == 12)
        cout << 'Q';
    else if(value == 13)
        cout << 'K';
    else
        cout << value;

    if(suit == 1)
        cout << 'C';
    if(suit == 2)
        cout << 'D';
    if(suit == 3)
        cout << 'H';
    if(suit == 4)
        cout << 'S';
}

void Game::display() {
    cout << "PLAYER  " << status + 1 << "  TURN" << endl;
    cout << "P1:  ";
    for(int i = 0; i < player1.size(); i++) {
        player1[i].display();
        cout << "  ";
    }
    cout << player1.size() << endl << endl << "Pile:  ";
//    pile.display();
    cout << "  " << deck.size() << endl << endl << "P2:  ";
    for(int i = 0; i < player2.size(); i++) {
        player2[i].display();
        cout << "  ";
    }
    cout << player2.size() << endl << endl;
}

void Game::execute() {
    int a=0,b=0,c=0;

    if(player1[0].getSuit() == player1[1].getSuit()) {
        if((player1[0].getValue() == (player1[1].getValue()+1))||(player1[0].getValue() == (player1[1].getValue()-1))) {
            a = 4;
        } else {
            a = 1;
        }
    } else if(player1[0].getValue() == player1[1].getValue()) {
        a = 3;
    } else if((player1[0].getValue() == (player1[1].getValue()+1))||(player1[0].getValue() == (player1[1].getValue()-1))) {
        a = 2;
    } else {
        a = 0;
    }
    cout << "A: " << a;


    if(player2[0].getSuit() == player2[1].getSuit()) {
        if((player2[0].getValue() == (player2[1].getValue()+1))||(player2[0].getValue() == (player2[1].getValue()-1))) {
            b = 4;
        } else {
            b = 1;
        }
    } else if(player2[0].getValue() == player2[1].getValue()) {
        b = 3;
    } else if((player2[0].getValue() == (player2[1].getValue()+1))||(player2[0].getValue() == (player2[1].getValue()-1))) {
        b = 2;
    } else {
        b = 0;
    }
    cout << "B: " << b;

    if(player3[0].getSuit() == player3[1].getSuit()) {
        if((player3[0].getValue() == (player3[1].getValue()+1))||(player3[0].getValue() == (player3[1].getValue()-1))) {
            c = 4;
        } else {
            c = 1;
        }
    } else if(player3[0].getValue() == player3[1].getValue()) {
        c = 3;
    } else if((player3[0].getValue() == (player3[1].getValue()+1))||(player3[0].getValue() == (player3[1].getValue()-1))) {
        c = 2;
    } else {
        c = 0;
    }
    cout << "C: " << c << endl;



    if(a > b) {
        if(a > c) {
            cout << "PLAYER 1" << endl;
        }
    }
    if(b>a) {
        if(b>c) {
            cout << "PLAYER 2" << endl;
        }
    }
    if(c>a) {
        if(c>b) {
            cout << "PLAYER 3" << endl;
        }
    }

}

int main() {
    srand(time(0));
    Game Crazy8;
    Crazy8.execute();
    return 0;
}

