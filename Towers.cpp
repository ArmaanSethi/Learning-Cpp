#include <iostream>
#include <windows.h>
#include <ctime>

COORD coord = {0,0};

using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    Node(int d, Node *n){data = d;next = n;}
    int getData(){return (data);}
    Node* getNext(){return next;}
    void setNext(Node *n){next = n;}
};

class Stack
{
private:
    Node *first;
public:
    Stack()
    {
        first = NULL;
    }
    void push(int x);
    void print(int x);
    int pop();
    void setup(int n)
    {
        for(int i = 0; i < n; i++)
           push(n-i);
    };
};

class Tower
{
private:
    Stack s1, s2, s3;
    int num_moves;
    int num;
public:
    Tower(int n)
    {
        s1.setup(n);
        num_moves = 0;
        num = n;
    }
    void execute();
    void display();
    void move1(Stack &from,Stack &to,Stack &temp);
    void move2(Stack &from,Stack &to,Stack &temp);
    void move3(Stack &from,Stack &to,Stack &temp);
    void move4(Stack &from,Stack &to,Stack &temp);
};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Stack::push(int n)
{
    if(first == NULL)
    {
        first = new Node(n,NULL);
    }else
    {
        Node *current = first;
        while(current -> getNext() != NULL)
        {
            current = current->getNext();
        }
        current->setNext(new Node(n, current->getNext()));
    }
    cout << endl;
}

int Stack::pop()
{
    int x;
    if(first -> getNext() == NULL)
    {
        x = first ->getData();
        first = first -> getNext();
    }else
    {
        Node *current = first;
        while(current -> getNext() ->getNext() != NULL)
        {
            current = current->getNext();
        }
        x = current ->  getNext() -> getData();
        current->setNext(current->getNext()->getNext());
    }
    return x;
}

void Stack::print(int x)
{
    int y = 25;
    if(first == NULL)
    {
        cout << "No Stack" << endl;
    }else
    {
        Node *current = first;
        while(current != NULL)
        {
            gotoxy(x, y-=2);
            cout << current -> getData() << "  ";
            current = current -> getNext();
        }//cout << endl;
    }
}

void Tower::move1(Stack &from,Stack &to,Stack &temp)
{
    to.push(from.pop());
    num_moves++;
    Sleep(600);
    display();
}
void Tower::move2(Stack &from,Stack &to,Stack &temp)
{
    move1(from,temp,to);
    move1(from,to,temp);
    move1(temp,to,from);
}
void Tower::move3(Stack &from,Stack &to,Stack &temp)
{
    move2(from,temp,to);
    move1(from,to,temp);
    move2(temp,to,from);
}
void Tower::move4(Stack &from,Stack &to,Stack &temp)
{
    move3(from,temp,to);
    move1(from,to,temp);
    move3(temp,to,from);
}

void Tower::display()
{
    system("CLS");
    gotoxy(5, 25);
    cout << "S1  ";
    s1.print(5);
    gotoxy(25,25);
    cout << "S2  ";
    s2.print(25);
    gotoxy(45,25);
    cout << "S3  ";
    s3.print(45);
}
void Tower::execute()
{
    //cout << num<<endl;
    display();

    if(num == 4)
        move4(s1,s2,s3);
    else if(num == 3)
        move3(s1,s2,s3);
    else if(num == 2)
        move2(s1,s2,s3);
    else if(num == 1)
        move1(s1,s2,s3);

    cout << endl;
    display();
    cout << endl << "NUM-M: " << num_moves << endl;
}

int main()
{
    int x = 0;
    cout << "Height: " << endl;
    cin >> x;
    Tower t1(x);
    t1.execute();
    return 0;
}
