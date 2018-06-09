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
    Card pile;
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
    deck.resize(52);

    for(int i = 0; i < 52; i++)
        deck[i].set((i%13)+1, (i/13)+1);

    random_shuffle(deck.begin(),deck.end());

    int a[20];

    for(int i = 0; i < 7; i++) {
        player1.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
    for(int i = 0; i < 7; i++) {
        player2.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
    pile = deck[deck.size()-1];
    deck.pop_back();
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
    pile.display();
    cout << "  " << deck.size() << endl << endl << "P2:  ";
    for(int i = 0; i < player2.size(); i++) {
        player2[i].display();
        cout << "  ";
    }
    cout << player2.size() << endl << endl;
}

void Game::pass() {
    cout << "YOU PASS" << endl;
    if((status%2) == 0) {
        player1.push_back(deck[deck.size()-1]);
        deck.pop_back();
    } else if((status%2) == 1) {
        player2.push_back(deck[deck.size()-1]);
        deck.pop_back();
    }
    Sleep(500);
}

void Game::playCard() {
    if((status%2) == 0) {
        if(player1[hand].getValue() == 8) {
            cout << endl << "What suit would you like? (1 for C, 2 for D, 3 for H, 4 for S" << endl;
            int choice;
            cin >> choice;
            pile.set(player1[hand].getValue(), choice);
            player1.erase(player1.begin() + hand);
        } else if((player1[hand].getValue() == pile.getValue()) || (player1[hand].getSuit() == pile.getSuit())) {
            pile.set(player1[hand].getValue(), player1[hand].getSuit());
            player1.erase(player1.begin() + hand);
        } else {
            cout << endl << "INVALID CARD  ::  ";
            pass();
        }
    } else if((status%2) == 1) {
        if(player2[hand].getValue() == 8) {
            cout << endl << "What suit would you like? (1 for C, 2 for D, 3 for H, 4 for S" << endl;
            int choice;
            cin >> choice;
            pile.set(player2[hand].getValue(), choice);
            player2.erase(player2.begin() + hand);
        } else if((player2[hand].getValue() == pile.getValue()) || (player2[hand].getSuit() == pile.getSuit())) {
            pile.set(player2[hand].getValue(), player2[hand].getSuit());
            player2.erase(player2.begin() + hand);
        } else {
            cout << endl << "INVALID CARD  ::  ";
            pass();
        }
    }
}

void Game::execute() {
    while((player1.size() > 0) && (player2.size() > 0)) {
        display();
        cout << "Which Card do you want to play? (starts with 0). Negative Number to Pass" << endl;
        cin >> hand;
        if(hand < 0)
            pass();
         else
            playCard();
        system("cls");
        status = (status+1)%2;
    }

    if(player1.size() == 0)
        cout << "PLAYER 1 WINS!!" << endl;
    else if(player2.size() == 0)
        cout << "PLAYER 2 WINS!!" << endl;
    else
        cout << "Magic" << endl;

}

int main() {
    srand(time(0));
    Game Crazy8;
    Crazy8.execute();
    return 0;
}
