/*
*Piglatin
*Armaan Sethi
*1/7/13
*/
#include <iostream>
#include <string>

using namespace std;

void input(string &phrase)
{
    cout << "Input a word: ";
    getline(cin, phrase);
}

/*string get_piglatin(string word)
{
    string word2;
    if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e'|| word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o' || word[0] == 'O' || word[0] == 'u' || word[0] == 'U')
    {
        word2 += (word + "-way");
        cout << word2;
    }
    else if(word[0] == 'Q'&& word[1] == 'u' || word[0] == 'q'&& word[1] == 'u' )
    {
//       for(int i = 2; i < word.size(); i++)
//           word2 += word[i];

        word2 += word.erase(0,2) + "-quay";
        cout << word2;
    }
    else
    {
        word2 += word.erase(0,1) + "-" + word[0] + "ay";
        cout << word2;
    }
    return word2;
}
*/



void output(string phrase_i)
{
    string word, word2;
    string phrase_o;
    int length = phrase_i.size();
    int num_words = 0;
    for (int i = 0; i < length; i++)
    {
        if(phrase_i[i] == ' ')
        {
            num_words++;
        }
    }
    for (int x = 0; x < num_words; x++)
    {
        for(int i = 0; i < length; i++)
        {
            if (phrase_i[i] == ' ')
            {
                //cout << phrase_i << endl << word;
                for( int a = 0; a < i; a++)
                    word += phrase_i[a];
                phrase_i.erase(0 , i + 1);
                if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e'|| word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o' || word[0] == 'O' || word[0] == 'u' || word[0] == 'U')
                    word2 += (word + "-way");
                else if(word[0] == 'Q'&& word[1] == 'u' || word[0] == 'q'&& word[1] == 'u' )
                    word2 += word.erase(0,2) + "-quay";
                else
                    word2 += word.erase(0,1) + "-" + word[0] + "ay";
                phrase_o += word2;
            }
        }
    }
    cout << phrase_o;
}

int main()
{
    string phrase;
    input(phrase);
    output(phrase);
    return 0;
}
