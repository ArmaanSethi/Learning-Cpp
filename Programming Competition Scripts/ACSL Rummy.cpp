#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_CARDS = 7;

void input(string cards[], int suit[], int value[])
{
    for(int a = 0; a < NUM_CARDS; a++)
    {
        cin >> cards[a];

        if(cards[a][1] == 'S') suit[a] = 4;
        if(cards[a][1] == 'H') suit[a] = 3;
        if(cards[a][1] == 'C') suit[a] = 2;
        if(cards[a][1] == 'D') suit[a] = 1;

        if(cards[a][0] == 'A')
            value[a] = 1;
        else if(cards[a][0] == 'T')
            value[a] = 10;
        else if(cards[a][0] == 'J')
            value[a] = 11;
        else if(cards[a][0] == 'Q')
            value[a] = 12;
        else if(cards[a][0] == 'K')
            value[a] = 13;
        else value[a] = (cards[a][0] - '0');
    }
    cout << endl;
}


void sort_suit(string cards[], int suit[], int value[])
{
    for(int b = 0; b < NUM_CARDS - 1; b++)
    {
        for(int a = 0; a < NUM_CARDS - 1; a++)
        {
            if ((suit[a]) < (suit[a+1]))
            {
                swap(suit[a], suit[a+1]);
                swap(cards[a], cards[a+1]);
                swap(value[a], value[a+1]);
            }
        }
    }
}

void sort_value(string cards[], int suit[], int value[])
{
    for(int b = 0; b < NUM_CARDS - 1; b++)
    {
        for(int a = 0; a < NUM_CARDS - 1; a++)
        {
            if ((value[a]) < (value[a+1]))
            {
                swap(value[a], value[a+1]);
                swap(cards[a], cards[a+1]);
                swap(suit[a], suit[a+1]);
            }
        }
    }
}

void sets(string cards[], int suit[], int value[], string out)
{
    string temp;
    cout << "RUN of 4: " << endl;
    sort_value(cards, suit, value);
    sort_suit(cards, suit, value);

    for(int a = NUM_CARDS - 1; a > 2; a--)
    {
        if(value[a] == (value[a-3] - 3) && value[a] != 20)
        {
            for(int c = a; c > a - 4; c--)
            {
                out += cards[c] + ", ";
                value[c] = 20;
                suit[c] = 10;
                cout << out << endl;
            }
        }
    }

    cout << "SET of 4: " << endl;
    sort_suit(cards, suit, value);
    sort_value(cards, suit, value);

    for(int a = 0; a < NUM_CARDS - 3; a++)
    {
        if(value[a] == value[a+3] && value[a] != 20)
        {
            for(int c = a; c < a + 4; c++)
            {
                out+= cards[c] + ", ";
                value[c] = 20;
                suit[c] = 10;
                cout << out << endl;
            }
        }
    }

    cout << "RUN of 3: " << endl;
    sort_value(cards, suit, value);
    sort_suit(cards, suit, value);

    for(int a = NUM_CARDS - 1; a >= 2; a--)
    {
        cout << value[a] << endl;
        if(value[a] == (value[a-2] - 2) && value[a] != 20)
        {
            for(int c = a; c > a - 3; c--)
            {
                out+= cards[c] + ", ";
                value[c] = 20;
                suit[c] = 10;
                cout << out << endl;
            }
        }
    }

    cout << "SET of 3: " << endl;
    sort_suit(cards, suit, value);
    sort_value(cards, suit, value);

    for(int a = NUM_CARDS - 1; a > 1; a--)
    {
        if(value[a] == value[a-2] && value[a] != 20)
        {
            for(int c = a - 2; c <= a; c++)
            {
                out += cards[c] + ", ";
                value[c] = 20;
                suit[c] = 10;
                cout << out << endl;
            }
        }
    }
    for(int a = 0; a < NUM_CARDS; a++)
    {
        if(value[a] != 20)
        {
            out+= cards[a] + ", ";
        }

    }

    cout << endl << "OUTPUT: " << out << endl;

}

/*void output(string cards[][NUM_PEOPLE])
{
    for(int i = 0; i < NUM_PEOPLE; i++)
    {
        for(int a = 0; a < NUM_CARDS; a++)
        {
            cout << endl << cards[i][a] << endl;
        }
    }
} */

int main()
{
    for(int i = 0; i < 1; i ++)
    {
        string cards[NUM_CARDS], output_cards;
        int card_suit[NUM_CARDS], card_value[NUM_CARDS];
        input(cards, card_suit, card_value);
        sets(cards, card_suit, card_value, output_cards);
        output_cards.erase(0, output_cards.length());
    }
    return 0;
}
