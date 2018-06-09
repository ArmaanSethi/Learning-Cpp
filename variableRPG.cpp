#include<iostream>
#include<windows.h>
#include<ctime>

int totalGold = 200;

using namespace std;

void arenaSign(){

    cout << "|-------|" << endl;
    cout << "| Arena |" << endl;
    cout << "|-------|" << endl << endl;

}

void skillSign(){

    cout << "|------|" << endl;
    cout << "|Skills|" << endl;
    cout << "|Center|" << endl;
    cout << "|------|" << endl;

}

void marketSign(){
    cout << "|------|" << endl;
    cout << "|Market|" << endl;
    cout << "|------|" << endl;
}

int intReturn(int a){

    int i;

    if (a == 1 || a == 3 || a == 5 || a == 7 || a == 9 || a == 11){
        i = ((a+1)/2);
    }

    else {
        i = (a/2);
    }

    return i;

}

int fightSim(string skill, string enemy, int att, int def, int hp, int elvl, int attB, int defB, bool &win){

    srand(time(NULL));
    bool enemyDead = false;
    bool youDead = false;
    bool fightOver = false;
    int yourHp = hp * 10;
    int enemyHp = elvl * 10;
    int a = att + attB;
    int d = def + defB;
    int hit[10];
    int xpGain = rand() % (elvl * 10);

    // ---1st Attack---
    if (a > elvl){

        hit[0] = rand() % ((a*10) - enemyHp);

    }

    else if (a < elvl){

        hit[0] = rand() % (((a*10) - 5) - enemyHp);

    }

    else {

        hit[0] = rand() % enemyHp;

    }

    //----Tells if the enemys dead
    if (hit[0] >= enemyHp){

        enemyDead = true;
        fightOver = true;

    }

    else {

        enemyHp = enemyHp - hit[0];
        enemyDead = false;

    }

    //-----The enemies hit
    if (elvl > d && !enemyDead){

        hit[1] = rand() % (elvl * 5);

    }

    else if (elvl < d && !enemyDead){

        hit[1] = rand() % (elvl * 3);

    }

    else if (elvl == d && !enemyDead){

        hit[1] = rand() % (elvl * 2);

    }

    //----are you dead
    if (hit[1] >= yourHp){

        youDead = true;
        fightOver = true;

    }

    else {

        yourHp = yourHp - hit[1];
        youDead = false;

    }


    // First set of output.
    if (!youDead){

        cout << " You hit a " << hit[0] << " on the " << enemy << "." << endl;
        cout << " The " << enemy << " has " << enemyHp << " hitpoints left." << endl;

    }

    else {

        cout << " You suck tits." << endl;

    }

    if (!enemyDead){

        Sleep(1500);
        cout << " The " << enemy << " hit a " << hit[1] << " on you." << endl;
        cout << " You have " << yourHp << " hitpoints left. " << endl;

    }

    else {

        win = true;
        cout << " You won the fight and gained " << xpGain << " xp in " << skill << "." << endl;

    }

    //-----2nd Attack--------
    if (!fightOver){

        if (a > elvl && !youDead){

            hit[2] = rand() % ((a*10) - enemyHp);

        }

        else if (a < elvl && !youDead){

            hit[2] = rand() % (((a*10) - 5) - enemyHp);

        }

        else if (!youDead){

            hit[2] = rand() % enemyHp;

        }

        //----Tells if the enemys dead
        if (hit[2] >= enemyHp){

            enemyDead = true;
            fightOver = true;

        }

        else {

            enemyHp = enemyHp - hit[2];
            enemyDead = false;

        }

        // ----Enemies Hit
        if (elvl > d && !enemyDead){

            hit[3] = rand() % (elvl * 5);

        }

        else if (elvl < d && !enemyDead){

            hit[3] = rand() % (elvl * 3);

        }

        else if (elvl == d && !enemyDead){

            hit[3] = rand() % (elvl * 2);

        }

        //----are you dead
        if (hit[3] >= yourHp){

            youDead = true;
            fightOver = true;

        }

        else {

            yourHp = yourHp - hit[3];
            youDead = false;

        }

        //----second set of output
        if (!youDead){

            Sleep(1500);
            cout << " You hit a " << hit[2] << " on the " << enemy << "." << endl;
            cout << " The " << enemy << " has " << enemyHp << " hitpoints left." << endl;

        }

        else if (youDead){

            cout << " Nice one faggot, you died." << endl;

        }

        if (!enemyDead){

            Sleep(1500);
            cout << " The " << enemy << " hit a " << hit[3] << " on you." << endl;
            cout << " You have " << yourHp << " hitpoints left. " << endl;

        }

        else if (enemyDead){

            win = true;
            cout << " You won the fight and gained " << xpGain << " xp in " << skill << "." << endl;

        }

    //-----3rd attack
        if (!fightOver){

            if (a > elvl && !youDead){

                hit[4] = rand() % ((a*10) - enemyHp);

            }

            else if (a < elvl && !youDead){

                hit[4] = rand() % (((a*10) - 5) - enemyHp);

            }

            else if (!youDead){

                hit[4] = rand() % enemyHp;

            }

            //----Tells if the enemys dead
            if ((hit[4] >= enemyHp)&& !youDead){

                enemyDead = true;

            }

            else if (!youDead){

                enemyHp = enemyHp - hit[4];
                enemyDead = false;

            }

            // ----Enemies Hit
            if (elvl > d && !enemyDead){

                hit[5] = rand() % (elvl * 5);

            }

            else if (elvl < d && !enemyDead){

                hit[5] = rand() % (elvl * 3);

            }

            else if (elvl == d && !enemyDead){

                hit[5] = rand() % (elvl * 2);

            }

            //----are you dead
            if ((hit[5] >= yourHp)&& !enemyDead){

                youDead = true;

            }

            else if (!enemyDead){

                yourHp = yourHp - hit[5];
                youDead = false;

            }

            //----third set of output
            if (!youDead){

                Sleep(1500);
                cout << " You hit a " << hit[4] << " on the " << enemy << "." << endl;
                cout << " The " << enemy << " has " << enemyHp << " hitpoints left." << endl;

            }

            else if (youDead){

                cout << " Nice one faggot, you died." << endl;

            }

            if (!enemyDead){

                Sleep(1500);
                cout << " The " << enemy << " hit a " << hit[5] << " on you." << endl;
                cout << " You have " << yourHp << " hitpoints left. " << endl;

            }

            else if (enemyDead){

                win = true;
                cout << " You won the fight and gained " << xpGain << " xp in " << skill << "." << endl;

            }

        }

    }

    if (win){
        return xpGain;
    }

    else {
        return 0;
    }

}

void checkLVLup(int a, int b, int c, int d, int e, int f, int &la, int &lb, int &lc, int &ld, int &le, int &lf){

    int XP[6];
    XP[0] = a;
    XP[1] = b;
    XP[2] = c;
    XP[3] = d;
    XP[4] = e;
    XP[5] = f;

    if (XP[0] > 20){
        la = 2;
        if (XP[0] > 45){
            la = 3;
            if (XP[0] > 75){
                la = 4;
                if (XP[0] > 120){
                    la = 5;
                }
            }
        }
    }

    if (XP[1] > 20){
        lb = 2;
        if (XP[1] > 45){
            lb = 3;
            if (XP[1] > 75){
                lb = 4;
                if (XP[1] > 120){
                    lb = 5;
                }
            }
        }
    }

    if (XP[2] > 20){
        lc = 2;
        if (XP[2] > 45){
            lc = 3;
            if (XP[2] > 75){
                lc = 4;
                if (XP[3] > 120){
                    lc = 5;
                }
            }
        }
    }

    if (XP[3] > 20){
        ld = 2;
        if (XP[3] > 45){
            ld = 3;
            if (XP[3] > 75){
                ld = 4;
                if (XP[3] > 120){
                    ld = 5;
                }
            }
        }
    }

    if (XP[4] > 20){
        le = 2;
        if (XP[4] > 45){
            le = 3;
            if (XP[4] > 75){
                le = 4;
                if (XP[4] > 120){
                    le = 5;
                }
            }
        }
    }

    if (XP[5] > 20){
        lf = 2;
        if (XP[5] > 45){
            lf = 3;
            if (XP[5] > 75){
                lf = 4;
                if (XP[5] > 120){
                    lf = 5;
                }
            }
        }
    }




}

void questGoblinKing(int clvl, int pflvl){

    char a;

    system("cls");
    cout << "      You decide to help the town. You enter the town, " << endl;
    cout << "          looking for signs of mass destrution." << endl;
    cout << "  You see boys and girls everywhere, running and playing." << endl;
    cout << "You wonder to youself how this could be? Have you heard wrong?" << endl << endl;
    system("pause");
    system("cls");
    cout << "All the sudden theres a giant crash! You turn around to people" << endl;
    cout << "  scatted across the streets, and then you see it." << endl;
    cout << "A huge goblin is running through the streets, knocking over buildings" << endl;
    cout << "            and doing harm to all the people!" << endl;
    system("pause");
    system("cls");
    cout << "Would you like to [f] fight the goblin or [r] run in a near shelter?" << endl;
    cin >> a;

    if (a == 'f'){
        cout << "You decide to fight the goblin." << endl;
        cout << "As you begin running towards it, " << endl;
        cout << "you notice an object flying towards you." << endl;
    }

    else if (a == 'r'){
        cout << "You run into the shelter." << endl;
    }

    else {

    }

}

void mainGame(int a, int b, int c, int d, int e, int f, int la, int lb, int lc, int ld, int le, int lf){

    srand(time(NULL));
    int XP[6];
    XP[0] = a;
    XP[1] = b;
    XP[2] = c;
    XP[3] = d;
    XP[4] = e;
    XP[5] = f;
    int LVL[6];
    LVL[0] = la;
    LVL[1] = lb;
    LVL[2] = lc;
    LVL[3] = ld + 1;
    LVL[4] = le;
    LVL[5] = lf + 1;
    bool wep[4];
    wep[0] = false;
    wep[1] = false;
    wep[2] = false;
    wep[3] = false;
    bool arm[4];
    arm[0] = false;
    arm[1] = false;
    arm[2] = false;
    arm[3] = false;
    bool questStarted = false;
    int plates = 0;
    int boost[2];
    boost[0] = 0;
    boost[1] = 0;
    int ap = 3;
    int day = 3;

    labelGame:
    while ( ap > 0 ){

    checkLVLup(XP[0], XP[1], XP[2], XP[3], XP[4], XP[5], LVL[0], LVL[1], LVL[2], LVL[3], LVL[4], LVL[5]);

    a:
    string move1;
    system("cls");
    cout << "          You are on day " << day << "." << endl;
    cout << "        You have " << ap << " ap left." << endl;
    cout << "        What do you want to do?" << endl;
    cout << "    [f] Fight Arena [sc] Skill Center" << endl;
    cout << "    [m] Market      [s] Stats " << endl;
    cout << "                ";
    cin >> move1;

    if (move1 == "f"){

        string move2;

        system("cls");
        arenaSign();
        cout << endl;
        cout << " Enter s to begin a new fight. " << endl;
        cout << "  Enter x to get out of here." << endl;
        cout << "            ";
        cin >> move2;

        if (move2 == "s"){

            string move3;

            qwerty:
            system("cls");
            cout << "  What skill do you want to be trained? " << endl;
            cout << " [a] Attack  [d] Defense  [hp] Hitpoints" << endl;
            cout << "                  ";
            cin >> move3;

            if (move3 == "a"){

                int elvl = intReturn(day);
                int goldGiven = rand() % (elvl*20);
                int xpGain;
                string d;
                bool fightWon = false;

                system("cls");
                arenaSign();
                cout << "You are now fighting a level " << elvl << " goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "             ";
                cin >> d;

                xpGain = fightSim("attack", "goblin", LVL[0], LVL[1], LVL[2], elvl, boost[0], boost[1], fightWon);
                if (fightWon){
                    totalGold = totalGold + goldGiven;
                    cout << " You were given " << goldGiven << " gp for winning the fight." << endl;
                    XP[0] = xpGain + XP[0];
                }
                cout << " You now have " << XP[0] << " xp in attack and " << totalGold << " gp." << endl;
                system("pause");
                --ap;

            }

            else if (move3 == "d"){

                string d;
                int elvl = intReturn(day);
                int goldGiven = rand() % (elvl*20);
                int xpGain;
                bool fightWon = false;

                system("cls");
                arenaSign();
                cout << "You are now fighting a level " << elvl << " goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "            ";
                cin >> d;

                xpGain = fightSim("defense", "goblin", LVL[0], LVL[1], LVL[2], elvl, boost[0], boost[1], fightWon);
                if (fightWon){
                    totalGold = totalGold + goldGiven;
                    cout << " You were given " << goldGiven << " gp for winning the fight." << endl;
                    XP[1] = xpGain + XP[1];
                }
                cout << " You now have " << XP[1] << " xp in defense and " << totalGold << " gp." << endl;
                system("pause");
                --ap;

            }

            else if (move3 == "hp"){

                string d;
                int xpGain;
                int elvl = intReturn(day);
                int goldGiven = rand() % (elvl*20);
                bool fightWon = false;

                system("cls");
                arenaSign();
                cout << "You are now fighting a level " << elvl << " goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "            ";
                cin >> d;

                xpGain = fightSim("hitpoints", "goblin", LVL[0], LVL[1], LVL[2], elvl, boost[0], boost[1], fightWon);
                if (fightWon){
                    totalGold = totalGold + goldGiven;
                    cout << " You were given " << goldGiven << " gp for winning the fight." << endl;
                    XP[1] = xpGain + XP[1];
                }
                cout << " You now have " << XP[2] << " xp in hitpoints and " << totalGold << " gp." << endl;
                system("pause");
                --ap;

            }

            else {

                cout << "Invalid input. Please try again." << endl;
                Sleep(3000);
                goto qwerty;

            }

        }

        else if (move2 == "x"){

            system("cls");
            cout << "You are now leaving the arena." << endl;
            Sleep(2000);
            goto a;

        }

    }

    else if (move1 == "sc"){

        string moves;

        redo:
        system("cls");
        skillSign();
        cout << "           Welcome to the skilling center." << endl;
        cout << "        Enter x to exit or a to begin skilling." << endl;
        cout << "    You may also enter s to goto the skill store." << endl;
        cin >> moves;

        if (moves == "a"){

            string movec;
            srand(time(NULL));

            retry:
            system("cls");
            skillSign();
            cout << "You have " << totalGold << " gold pieces." << endl << endl;
            cout << "To skill, all you need to do is have the money" << endl;
            cout << "             and 1 action point." << endl;
            cout << "To begin, select the skill your'd like to train." << endl;
            cout << "[c] Crafting- " << LVL[3]*5 << " [z] Zoology- " << LVL[4]*10 <<" [pf] Path Finding- " << LVL[5]*7 << " " << endl;
            cin >> movec;

            if (movec == "c" && totalGold > (LVL[3]*5)){

                int xpGiven = rand() % (LVL[3]*5);
                XP[3] = XP[3] + xpGiven;
                totalGold = totalGold - (LVL[3]*5);

                system("cls");
                cout << "     You just trained Crafting and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[3] << " xp in crafting and " << totalGold << " total gold left!" << endl;
                system("pause");
                --ap;

            }

            else if (movec == "z" && totalGold > (LVL[4]*10)){

                int xpGiven = rand() % (LVL[4]*10);
                XP[4] = XP[4] + xpGiven;
                totalGold = totalGold - (LVL[4]*10);

                system("cls");
                cout << "     You just trained zoology and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[4] << " xp in zoology and " << totalGold << " total gold left!" << endl;
                system("pause");
                --ap;

            }

            else if (movec == "pf" && totalGold > (LVL[5]*7)){

                int xpGiven = rand() % (LVL[5]*7);
                XP[5] = XP[5] + xpGiven;
                totalGold = totalGold - (LVL[5]*7);

                system("cls");
                cout << "     You just trained path finding and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[5] << " xp in path finding and " << totalGold << " total gold left!" << endl;
                system("pause");
                --ap;

            }

            else {

                cout << "Invalid input. Please try again." << endl;
                Sleep(2000);
                goto retry;

            }

        }

        else if (moves == "s"){

            string skillChoice;
            int buy;

            skillStore:
            system("cls");
            skillSign();
            cout << "    Welcome to the skill store." << endl;
            cout << " Here is where you can purchase items " << endl;
            cout << "     based on you skill levels." << endl;
            cout << "         Enter x to exit " << endl;
            cout << "What skill items would you like to view?" << endl;
            cout << " [c] Crafting - Level " << LVL[3] << endl;
            cout << " [z] Zoology - Level " << LVL[4] << endl;
            cout << " [pf] Path Finding - Level " << LVL[5] << endl;
            cin >> skillChoice;

            if (skillChoice == "c"){

                system("cls");
                skillSign();
                cout << endl;
                cout << "You have " << totalGold << " gp." << endl << endl;
                cout << "Now showing crafting items. " << endl;
                cout << "These items boost your fighting skills" << endl;
                cout << "[Choice #] - Item Name - [Price] - [Level Req.] - [Skill Boost/Amount]" << endl;
                cout << "[1] - Armour Plating - [20gp] - [2] - [Defense/1]" << endl;
                cout << "[2] - Advanced Armour Plating - [80gp] - [4] - [Defense/3]" << endl;
                cout << "[3] - Sword Plating - [50gp] - [3] - [Attack/2]" << endl;
                cout << "You may have a total of 5 platings. You have " << plates << "." << endl;
                cin >> buy;

                if (buy == 1 && totalGold >= 20 && LVL[3] >= 2 && plates < 5){

                    ++plates;
                    totalGold = totalGold - 20;
                    boost[1] = boost[1] + 1;

                    cout << "You have purchased an Armour Plating." << endl;
                    cout << "You now have " << totalGold << " gp and " << plates << " plates" << endl;
                    cout << "Your defense boost is now " << boost[1] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 2 && totalGold >= 80 && LVL[3] >= 4 && plates < 5){

                    ++plates;
                    totalGold = totalGold - 80;
                    boost[1] = boost[1] + 3;

                    cout << "You have purchased an Advanced Armour Plating." << endl;
                    cout << "You now have " << totalGold << " gp and " << plates << " plates" << endl;
                    cout << "Your defense boost is now " << boost[1] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 3 && totalGold >= 50 && LVL[3] >= 3 && plates < 5){

                    ++plates;
                    totalGold = totalGold - 50;
                    boost[0] = boost[0] + 2;

                    cout << "You have purchased an Sword Plating." << endl;
                    cout << "You now have " << totalGold << " gp and " << plates << " plates" << endl;
                    cout << "Your attack boost is now " << boost[0] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 1 || buy == 2 || buy == 3){

                    cout << "You can't purchase that item." << endl << endl;
                    system("pause");
                    system("cls");
                    goto skillStore;

                }

                else {

                    cout << "Invalid input. Please try again." << endl;
                    Sleep(2000);
                    goto skillStore;

                }

            }

            else if (skillChoice == "z"){

                system("cls");
                skillSign();
                cout << endl;
                cout << "You have " << totalGold << " gp." << endl << endl;
                cout << "Now showing zoology items. " << endl;
                cout << "These items boost your fighting skills" << endl;
                cout << "[Choice #] - Item Name - [Price] - [Level Req.] - [Skill Boost/Amount]" << endl;
                cout << "[1] - Parrot - [100gp] - [2] - [All/2]" << endl;
                cout << "[2] - Wolf - [160gp] - [3] - [All/4]" << endl;
                cout << "[3] - Velociraptor - [300gp] - [5] - [All/10]" << endl;
                cin >> buy;

                if (buy == 1 && totalGold >= 100 && LVL[4] >= 2){

                    totalGold = totalGold - 100;
                    boost[0] = boost[0] + 2;
                    boost[1] = boost[1] + 2;

                    cout << "You have purchased a parrot." << endl;
                    cout << "You now have " << totalGold << " gp." << endl;
                    cout << "Your defense boost is now " << boost[1] << "." << endl;
                    cout << "Your attack boost is now " << boost[0] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 2 && totalGold >= 160 && LVL[4] >= 3){

                    totalGold = totalGold - 160;
                    boost[0] = boost[0] + 4;
                    boost[1] = boost[1] + 4;

                    cout << "You have purchased a wolf." << endl;
                    cout << "You now have " << totalGold << " gp." << endl;
                    cout << "Your defense boost is now " << boost[1] << "." << endl;
                    cout << "Your attack boost is now " << boost[0] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 3 && totalGold >= 300 && LVL[4] >= 5){

                    totalGold = totalGold - 300;
                    boost[0] = boost[0] + 10;
                    boost[1] = boost[1] + 10;

                    cout << "You have purchased a velociraptor." << endl;
                    cout << "You now have " << totalGold << " gp." << endl;
                    cout << "Your defense boost is now " << boost[1] << "." << endl;
                    cout << "Your attack boost is now " << boost[0] << "." << endl;

                    system("pause");
                    goto skillStore;

                }

                else if (buy == 1 || buy == 2 || buy == 3){

                    cout << "You can't purchase that item." << endl << endl;
                    system("pause");
                    system("cls");
                    goto skillStore;

                }

                else {

                    cout << "Invalid input. Please try again." << endl;
                    Sleep(2000);
                    goto skillStore;

                }

            }

            else if (skillChoice == "pf"){

                system("cls");
                skillSign();
                cout << endl;
                cout << "You have " << totalGold << " gp." << endl << endl;
                cout << "Now showing path finding items. " << endl;
                cout << "These items are mainly used in quests." << endl;
                cout << "You unlock these according to the quests you have begun." << endl;
                cout << "[Choice #] - Item Name - [Price]" << endl;
                cin >> buy;

            }

            else if (skillChoice == "x"){

                system("cls");
                cout << "Now leaving the skill market." << endl;
                Sleep(2000);
                goto redo;

            }

            else {

                system("cls");
                cout << "Invalid input. Please try again." << endl;
                Sleep(2000);
                goto skillStore;

            }

        }

        else if (moves == "x"){

            system("cls");
            cout << "You are now leaving the skill center." << endl;
            Sleep(2000);
            goto a;

        }

        else {

            cout << "Invalid input. Please try again." << endl;
            Sleep(2000);
            goto redo;

        }

    }

    else if (move1 == "m"){

        char c;

        rere:
        system("cls");
        marketSign();
        cout << "  Welcome to the market!" << endl;
        cout << "You have " << totalGold << " GP to spend." << endl;
        cout << "   Are you interested in" << endl;
        cout << " [b] buying    [s] selling " << endl;
        cout << " [j] jobs      [q] quests  " << endl;
        cout << "      Enter x to exit." << endl;
        cin >> c;

        if (c == 'b'){

            int choice;
            char aw;

            rerea:
            system("cls");
            marketSign();
            cout << "GP - " << totalGold << endl << endl;
            cout << "Would you like to browse" << endl;
            cout << "[a] Armour or [w] Weapons?" << endl;
            cin >> aw;

            if (aw == 'w'){

                rew:
                system("cls");
                marketSign();
                cout << "GP - " << totalGold << endl << endl;
                cout << "[Selection #] Item Name - [Gp Price] - [Attack Lvl Req.] - [Attack Max Hit Boost]" << endl;
                cout << "[1] Bronze Dagger - [40] - [2] - [+2]  [3] Iron Dagger - [80] - [3] - [+3]" << endl;
                cout << "[2] Bronze Sword - [100] - [3] - [+4]  [4] Iron Sword - [160] - [4] - [+6]" << endl;
                cin >> choice;

                if (choice == 1 && totalGold >= 40){

                    totalGold = totalGold - 40;
                    wep[0] = true;
                    if (!wep[1] && !wep[2] && !wep[3]){
                        boost[0] = 2;
                    }
                    cout << "Have just bought the Bronze Dagger. Your current attack boost is " << boost[0] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 2 && totalGold >= 100){

                    totalGold = totalGold - 100;
                    wep[1] = true;
                    if (!wep[2] && !wep[3]){
                        boost[0] = 4;
                    }
                    cout << "Have just bought the Bronze Sword. Your current attack boost is " << boost[0] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 3 && totalGold >= 80){

                    totalGold = totalGold - 80;
                    wep[2] = true;
                    if (!wep[3]){
                        boost[0] = 3;
                    }
                    cout << "Have just bought the Iron Dagger. Your current attack boost is " << boost[0] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 4 && totalGold >= 160){

                    totalGold = totalGold - 160;
                    wep[3] = true;
                    boost[0] = 6;
                    cout << "Have just bought the Iron Sword. Your current attack boost is " << boost[0] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 1 || choice == 2 || choice == 3 || choice == 4){

                    cout << "Not enough GP to purchase." << endl;
                    Sleep(3000);
                    goto rerea;

                }

                else {

                    system("cls");
                    cout << "Invalid input. Please try again." << endl;
                    Sleep(3000);
                    goto rew;

                }
            }

            else if (aw == 'a'){

                rea:
                system("cls");
                marketSign();
                cout << "GP - " << totalGold << endl << endl;
                cout << " [Selection #] Item Name - [Gp Price] - [Defense Lvl Req.] - [Defense Boost]" << endl;
                cout << "[1] Bronze Armour - [120] - [3] - [+4] [2] Iron Armour - [200] - [5] - [+6]" << endl;
                cin >> choice;

                if (choice == 1 && totalGold >= 120 && LVL[2] >= 3){

                    totalGold = totalGold - 120;
                    arm[0] = true;
                    if (!arm[1]){
                        boost[1] = 4;
                    }
                    cout << "Have just bought Bronze Armour. Your current defense boost is " << boost[1] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 2 && totalGold >= 200 && LVL[2] >= 5){

                    totalGold = totalGold - 200;
                    arm[1] = true;
                    boost[0] = 6;

                    cout << "Have just bought Iron Armour. Your current defense boost is " << boost[1] << "." << endl;
                    cout << "                You now have " << totalGold << " GP" << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 1 || choice ==2){

                    system("cls");
                    cout << "Not enough money or not high enough level." << endl;
                    Sleep(3000);
                    goto rerea;

                }

                else {

                    system("cls");
                    cout << "Invalid input. Please try again." << endl;
                    Sleep(3000);
                    goto rea;

                }
            }

            else if (aw == 'x'){

                system("cls");
                cout << "Now leaving to the market menu." << endl;
                Sleep(3000);
                goto rere;

            }

            else {

                system("cls");
                cout << "Invalid input. Please try again." << endl;
                Sleep(2500);
                goto rerea;

            }

        }

        else if (c == 's'){

            int choice;
            char aw;

            reres:
            system("cls");
            marketSign();
            cout << "GP - " << totalGold << endl << endl;
            cout << "Would you like to browse" << endl;
            cout << "[a] Armour or [w] Weapons?" << endl;
            cin >> aw;

            if (aw == 'a'){

                system("cls");
                marketSign();
                cout << "GP - " << totalGold << endl << endl;
                cout << "[Selection #] - Item Name - [Sell Value]" << endl;
                cout << "      [1] - Bronze Armour - [80]" << endl;
                cout << "       [2] - Iron Amour - [110]" << endl;
                cout << "             [3] to exit" << endl;
                cin >> choice;

                if (choice == 1 && arm[0]){

                    totalGold = totalGold + 80;
                    arm[0] = false;

                    cout << "You sold your old Bronze Armour for 80 GP. " << endl;
                    cout << "     You now have " << totalGold << "GP. " << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 2 && arm[1]){

                    totalGold = totalGold + 110;
                    arm[1] = false;

                    cout << "You sold your old Iron Armour for 110 GP. " << endl;
                    cout << "     You now have " << totalGold << "GP. " << endl;
                    system("pause");
                    goto rere;

                }

                else if (choice == 1 || choice == 2){

                    system("cls");
                    cout << "You dont have that item!" << endl;
                    Sleep(2500);
                    goto reres;

                }

                else if (choice == 3){

                        system("cls");

                }

                else {



                }


            }

        }

        else if (c == 'q'){

            int quest;

            system("cls");
            marketSign();
            cout << endl;
            cout << "Welcome to the quest menu!" << endl;
            cout << "You may enter x to exit the menu." << endl;
            cout << "Enter the quest number to look at the reqs." << endl;
            cin >> quest;

            if (day > 3 && !questStarted){

                cout << " [47] Goblin King " << endl;

            }

            if (quest == 47){

                char qc;

                system("cls");
                cout << "               Goblin King" << endl << endl;
                cout << "Help! Help! A local tribe of goblins have been" << endl;
                cout << "  terrorizing the local towns people!" << endl << endl;
                cout << "To help the town try to stop these pests, " << endl;
                cout << "your'll need level 2 crafting, 2 path finding" << endl;
                cout << "and the ability to defeat a level 4 goblin king." << endl << endl;
                cout << "        Enter s to begin, or x to exit" << endl;
                cin >> qc;

                if (qc == 's' && LVL[3] >= 2 && LVL[5] >= 2){

                    cout << "OK then, here you go!" << endl;
                    Sleep(3000);
                    questGoblinKing(LVL[3], LVL[5]);
                    ap = 0;

                }

            }

        }

        else if (c == 'x'){

            system("cls");
            cout << "Now leaving the market..." << endl;
            Sleep(2500);
            goto a;

        }

        else {

            system("cls");
            cout << "Invalid input. Please try again." << endl;
            Sleep(2500);
            goto rere;

        }

    }

    else if (move1 == "s"){

        system("cls");
        cout << endl;
        cout << "You total gp is " << totalGold << " ." << endl << endl;
        cout << "Attack xp - " << XP[0] << " - Attack Lvl - " << LVL[0] << endl;
        cout << "Defense xp - " << XP[1] << " - Defense Lvl - " << LVL[1] << endl;
        cout << "Hitpoints xp - " << XP[2] << " - Hitpoints Lvl - " << LVL[2] << endl;
        cout << "Crafting xp - " << XP[3] << " - Crafting Lvl - " << LVL[3] << endl;
        cout << "Zoology xp - " << XP[4] << " - Zoology Lvl - " << LVL[4] << endl;
        cout << "Path Finding xp - " << XP[5] << " - Path Finding Lvl - " << LVL[5] << endl << endl;
        cout << "Your current attack boost is " << boost[0] << "." << endl;
        cout << "Your current defense boost is " << boost[1] << "." << endl << endl;
        system("pause");
        goto a;

    }

    else {

        cout << "Invalid input. Please try again." << endl;
        Sleep(3000);
        goto a;

    }

    if (ap == 0){

        ++day;

        int buy;

        reret:
        system("cls");
        cout << "  You now 0 action points and " << totalGold << " gold pieces left." << endl;
        cout << "     You can buy more action points at the rate of" << endl;
        cout << " [1] 1 Action Point - 5gp or [2] 5 Action Points - 20gp" << endl;
        cout << "                   [3] to carry on." << endl;
        cin >> buy;

        if (buy == 1 && totalGold >= 5){

            totalGold = totalGold - 5;
            ++ap;
            cout << "You purchased 1 AP and now have " << ap << " AP and " << totalGold << " GP." << endl;
            goto a;

        }

        else if (buy == 2 && totalGold >= 20){

            totalGold = totalGold - 20;
            ap = ap + 5;
            cout << "You purchased 5 AP and now have " << ap << " AP and " << totalGold << " GP." << endl;
            goto a;

        }

        else if (buy == 2 || buy == 1){

            system("cls");
            cout << "Not enough cash. Going back to menu." << endl;
            Sleep(4000);
            goto reret;

        }

        else if (buy == 3){

            system("cls");

        }

        else {

            system("cls");
            cout << "Invalid input. Please try again." << endl;
            Sleep(3000);
            goto reret;

        }

        ap = ap + 3;

    }

    }


}

void game(int a, int b, int c, int d, int e, int f, int la, int lb, int lc, int ld, int le, int lf){

    // Level stuff
    int XP[6];
    XP[0] = a;
    XP[1] = b;
    XP[2] = c;
    XP[3] = d;
    XP[4] = e;
    XP[5] = f;
    int LVL[6];
    LVL[0] = la;
    LVL[1] = lb;
    LVL[2] = lc;
    LVL[3] = ld;
    LVL[4] = le;
    LVL[5] = lf;
    string move1;

    day1Start:
    system("cls");
    cout << "             Tutorial Time." << endl;
    cout << "      What do you want to do first?" << endl;
    cout << "    [f] Fight Arena [s] Skill Center" << endl;
    cout << "You may also enter x to go ahead to the game" << endl;
    cout << "              ";
    cin >> move1;

    if (move1 == "f"){

        string move2;

        system("cls");
        arenaSign();
        cout << "       Aw, the Arena. " << endl;
        cout << " Enter s to begin a new fight. " << endl;
        cout << "  Enter x to get out of here." << endl;
        cout << "            ";
        cin >> move2;

        if (move2 == "s"){

            string move3;

            qwerty:
            system("cls");
            cout << "  What skill do you want to be trained? " << endl;
            cout << " [a] Attack  [d] Defense  [hp] Hitpoints" << endl;
            cout << "                  ";
            cin >> move3;

            if (move3 == "a"){

                int xpGain;
                string d;
                bool a = true;

                system("cls");
                cout << "You are now fighting a level 1 goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "             ";
                cin >> d;

                xpGain = fightSim("attack", "goblin", LVL[0], LVL[1], LVL[2], 1, 0, 0, a);
                XP[0] = xpGain + XP[0];
                cout << " You now have " << XP[0] << " xp in attack." << endl;
                system("pause");
                goto day1Start;

            }

            else if (move3 == "d"){

                string d;
                int xpGain;
                bool a = true;

                system("cls");
                cout << "You are now fighting a level 1 goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "            ";
                cin >> d;

                xpGain = fightSim("defense", "goblin", LVL[0], LVL[1], LVL[2], 1, 0, 0, a);
                XP[1] = xpGain + XP[1];
                cout << " You now have " << XP[1] << " xp in defense." << endl;
                system("pause");
                goto day1Start;

            }

            else if (move3 == "hp"){

                string d;
                int xpGain;
                bool a = true;

                system("cls");
                cout << "You are now fighting a level 1 goblin." << endl;
                cout << "      Enter any key to begin." << endl;
                cout << "            ";
                cin >> d;

                xpGain = fightSim("hitpoints", "goblin", LVL[0], LVL[1], LVL[2], 1, 0, 0, a);
                XP[2] = xpGain + XP[2];
                cout << " You now have " << XP[2] << " xp in hitpoints." << endl;
                system("pause");
                goto day1Start;

            }

            else {

                cout << "Invalid input. Please try again." << endl;
                Sleep(3000);
                goto qwerty;

            }

        }

        else if (move2 == "x"){

            system("cls");
            cout << "You are now leaving the arena." << endl;
            Sleep(2000);
            goto day1Start;

        }

    }

    else if (move1 == "s"){

        string moves;

        redo:
        system("cls");
        skillSign();
        cout << "           Welcome to the skilling center." << endl;
        cout << "The skilling center is a place where you can train" << endl;
        cout << "   skills to improve your fighting and questing." << endl;
        cout << "        Enter x to exit or a to begin skilling." << endl;
        cin >> moves;

        if (moves == "a"){

            string movec;
            srand(time(NULL));

            retry:
            system("cls");
            skillSign();
            cout << "You have " << totalGold << " gold pieces." << endl << endl;
            cout << "To skill, all you need to do is have the money" << endl;
            cout << "             and 1 action point." << endl;
            cout << "To begin, select the skill your'd like to train." << endl;
            cout << "[c] Crafting- " << LVL[3]*5 << " [z] Zoology- " << LVL[4]*10 <<" [pf] Path Finding- " << LVL[5]*7 << " " << endl;
            cin >> movec;

            if (movec == "c" && totalGold > (LVL[3]*5)){

                int xpGiven = rand() % (LVL[3]*5);
                XP[3] = XP[3] + xpGiven;
                totalGold = totalGold - (LVL[3]*5);

                system("cls");
                cout << "     You just trained Crafting and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[3] << " xp in crafting and " << totalGold << " total gold left!" << endl;
                system("pause");
                goto day1Start;

            }

            else if (movec == "z" && totalGold > (LVL[4]*10)){

                int xpGiven = rand() % (LVL[4]*10);
                XP[4] = XP[4] + xpGiven;
                totalGold = totalGold - (LVL[4]*10);

                system("cls");
                cout << "     You just trained zoology and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[4] << " xp in zoology and " << totalGold << " total gold left!" << endl;
                system("pause");
                goto day1Start;

            }

            else if (movec == "pf" && totalGold > (LVL[5]*7)){

                int xpGiven = rand() % (LVL[5]*7);
                XP[5] = XP[5] + xpGiven;
                totalGold = totalGold - (LVL[5]*7);

                system("cls");
                cout << "     You just trained path finding and got "<< xpGiven << " xp!" << endl;
                cout << "You now have " << XP[5] << " xp in path finding and " << totalGold << " total gold left!" << endl;
                system("pause");
                goto day1Start;

            }

            else {

                cout << "Invalid input. Please try again." << endl;
                Sleep(2000);
                goto retry;

            }

        }

        else if (moves == "x"){

            system("cls");
            cout << "You are now leaving the skill center." << endl;
            Sleep(2000);
            goto day1Start;

        }

        else {

            cout << "Invalid input. Please try again." << endl;
            Sleep(2000);
            goto redo;

        }

    }

    else if (move1 == "x"){

        system("cls");
        cout << "Wow! Nice job completing your first day!" << endl;
        cout << "Enter any key to go on to the main game!" << endl;
        system("pause");
        mainGame(XP[0], XP[1], XP[2], XP[3], XP[4], XP[5], LVL[0], LVL[1], LVL[2], LVL[3], LVL[4], LVL[5]);

    }

    else {

        cout << "Invalid input. Please try again." << endl;
        Sleep(3000);
        goto day1Start;

    }

}

void preGame(){

    int boostChoice;
    int learnChoice;
    string choiceOutput;
    int XP[6];
    XP[0] = 0;
    XP[1] = 0;
    XP[2] = 0;
    XP[3] = 0;
    XP[4] = 0;
    XP[5] = 0;
    int LVL[6];
    LVL[0] = 1;
    LVL[1] = 1;
    LVL[2] = 1;
    LVL[3] = 1;
    LVL[4] = 1;
    LVL[5] = 1;

    learnAgain:
    system("cls");
    cout << "Ok. You may now choose 1 stat boost to begin," << endl;
    cout << "  one fighting start or one skilling stat" << endl << endl;
    cout << "   Fighting Boosts       Skilling Boosts" << endl;
    cout << "     [1] Attack           [4] Crafting  " << endl;
    cout << "     [2] Defense          [5] Zoology   " << endl;
    cout << "     [3] Hit Points       [6] Path Finding" << endl << endl;
    Sleep(4000);
    cout << "      WAIT! before you make your choose," << endl;
    cout << "    shouldnt you know what each skill is" << endl;
    cout << "        and what you can do with it?" << endl << endl;
    cout << "        Enter the number of the skill " << endl;
    cout << "     your'd like to learn about first." << endl;
    cout << "                  ";

    cin >> learnChoice;

    if (learnChoice == 1){


        system("cls");
        cout << "            You choose attack." << endl;
        cout << "       Attack is a fighting skill" << endl;
        cout << "which determines how hard you hit an enemy." << endl;
        cout << "     Beware through, if your attack is " << endl;
        cout << "     too far under an enemies defense," << endl;
        cout << "      you may not hit on them at all!" << endl;
        system("pause");

    }

    else if (learnChoice == 2){

        system("cls");
        cout << "         You choose defence." << endl;
        cout << "      Defense is a fighting skill" << endl;
        cout << "which determines how hard an enemy hits you." << endl;
        cout << "       If your defense is low, " << endl;
        cout << "    the enemy could hit much harder" << endl;
        cout << "       on you and potentially..." << endl;
        cout << "              kill you." << endl;
        system("pause");

    }

    else if (learnChoice == 3){

        system("cls");
        cout << " HP " << endl;
        system("pause");

    }

    else if (learnChoice == 4){

        system("cls");
        cout << " Crafting" << endl;
        system("pause");

    }

    else if (learnChoice == 5){

        system("cls");
        cout << " Zoology " << endl;
        system("pause");

    }

    else if (learnChoice == 6){

        system("cls");
        cout << " Path Finding" << endl;
        system("pause");

    }

    else {

        cout << "Invalid Input. Please try again." << endl;
        goto learnAgain;

    }

    tryagain:
    system("cls");
    cout << "              Lets try this again." << endl;
    cout << "Ok. You may now choose 1 stat boost to begin," << endl;
    cout << "  one fighting start or one skilling stat" << endl << endl;
    cout << "   Fighting Boosts       Skilling Boosts" << endl;
    cout << "     [1] Attack           [4] Crafting  " << endl;
    cout << "     [2] Defense          [5] Zoology   " << endl;
    cout << "     [3] Hit Points       [6] Path Finding" << endl << endl;
    cin >> boostChoice;

    if (boostChoice == 1){

        LVL[0] = 2;
        choiceOutput = "Attack";

    }

    else if (boostChoice == 2){

        LVL[1] = 2;
        choiceOutput = "Defence";

    }

    else if (boostChoice == 3){

        LVL[2] = 2;
        choiceOutput = "Hitpoints";

    }

    else if (boostChoice == 4){

        LVL[3] = 2;
        choiceOutput = "Crafting";

    }

    else if (boostChoice == 5){

        LVL[4] = 2;
        choiceOutput = "Zoology";

    }

    else if (boostChoice == 6){

        LVL[5] = 2;
        choiceOutput = "Path Finding";

    }

    else {

        cout << " Invalid input. Please try again." << endl;
        Sleep(2000);
        goto tryagain;

    }

    string b;

    cout << " Ok. Finally, your ready to begin." << endl;
    cout << "   Your boost choice was " << choiceOutput << "." << endl;
    cout << "    Enter any key to continue." << endl;
    cin >> b;
    game(XP[0], XP[1], XP[2], XP[3], XP[4], XP[5], LVL[0], LVL[1], LVL[2], LVL[3], LVL[4], LVL[5]);

}

void gameStart(){

    string start;

    restart:
    system("cls");
    cout << "You wake up in a forest. You see a unicorn." << endl;
    cout << "         Wow, your tripping balls.         " << endl;

    Sleep(4000);
    system("cls");
    cout << "  Each day the game gets a little harder.  " << endl;
    cout << "      You get 3 action points a day.       " << endl;

    Sleep(4000);
    system("cls");
    cout << "       Enter f to fight on that day.       " << endl;
    cout << "  You level up fighting skills this way.   " << endl;

    Sleep(4000);
    system("cls");
    cout << "        Enter s to skill that day.         " << endl;
    cout << "  You level up skilling skills this way.   " << endl;

    Sleep(4000);
    system("cls");
    cout << "     Enter a to begin your journey. Once you begin,    " << endl;
    cout << "you will view a short tutorial on skilling and fighting." << endl;
    cout << "           O, yeah, leveling up these skills " << endl;
    cout << "           helps you get a job and do quests." << endl;
    cout << "              Enter r to restart the intro." << endl;
    cout << "                      Press a to begin." << endl;
    cout << "                          ";

    rsdo:
    cin >> start;

    if (start == "r"){

        goto restart;

    }

    else if (start == "a"){

        preGame();

    }

    else {

        cout << "Invalid Input. Please try again." << endl;
        goto rsdo;

    }
}

int main(){

    system("Color a");
    string move;

    start:
    system("cls");
    cout << "RPG w/ Variables Test " << endl;
    cout << "   Enter s to begin   " << endl;
    cin >> move;

    if(move == "s"){

        gameStart();

    }

    else {

        cout << "Invalid Input. Please try again." << endl;
        Sleep(2000);
        goto start;

    }

    return 0;

}

