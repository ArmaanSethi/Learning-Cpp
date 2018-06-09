#include <iostream>
#include <string>

using namespace std;

int a = 0;

class Node
{
private:
    char data;
    Node *left;
    Node *right;
    double value;
public:
    Node(char d, Node *l,Node *r, double v)
    {
        data = d;left = l; right = r;value = v;
       /* if((d == '+')||(d == '-')||(d == '*')||(d == '%')||(d == '/')||(d == '^'))
        {
            value = -999;
        }else
        {
            value = v;
        };*/
    }
    char getData(){return (data);}
    double getValue(){return(value);}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    void setLeft(Node *n){left = n;}
    void setRight(Node *n){right = n;}
    void setValue(double x){value = x;}
};

class ETree
{
private:
    Node *root;
public:
    ETree()
    {
        root = NULL;
    }
    void execute();
    void insert(string &n, Node *current);
    void print(Node *current);
    void evaluate(Node *current);
};

void ETree::insert(string &input, Node *current)
{
    char c = input[0];
    int n = (c - '0');
    if(c == '(')
    {
        input.erase(0,2);
        c = input[0];
        input.erase(0,1);
        n = (c - '0')*-1;
    }
    if(c == '!')
    {
        cout << "!!!!!" << endl;
        input.erase(0,1);
        int x = (input[0] - '0')-1;
        cout << "X: " << x << endl;
        int y = (input[0] - '0');
        int z = x;
        for(int i = 0; i < z; i++)
        {
            y*=(x);
            x--;
        }
        cout << "Y: " << y << endl;
        current -> setValue(y);
        cout << "HI" << endl;
    }else{
    ///Place Left
    ///Place Right
    ///Evaluate
    if(input != "")
    {
        if(root == NULL)
        {
            root = new Node(c ,NULL, NULL, (n));
            input.erase(0,1);
            insert(input, root);
        }else
        {
            if(current -> getLeft() == NULL)
            {
                ///LEFT
                if((c == '+')||(c == '-')||(c == '*')||(c == '%')||(c == '/')||(c == '^')||(c=='#'))
                {
                    current -> setLeft(new Node(c ,NULL,NULL, (n)));
                    input.erase(0,1);
                    insert(input, current->getLeft());
                    insert(input, current);
                }else
                {
                    current -> setLeft(new Node(c ,NULL,NULL,(n)));
                    input.erase(0,1);
                    insert(input, current);
                }
            }else if(current -> getRight() == NULL)
            {
                ///RIGHT
                if((c == '+')||(c == '-')||(c == '*')||(c == '%')||(c == '/')||(c == '^')||(c=='#'))
                {
                    current -> setRight(new Node(c ,NULL,NULL, (n)));
                    input.erase(0,1);
                    insert(input, current->getRight());
                }else
                {
                    current -> setRight(new Node(c ,NULL,NULL, (n)));
                    input.erase(0,1);
                }
            }
            evaluate(current);
            //cout << current -> getValue();
        }
    }
    }
    //cout << endl;
}

void ETree::print(Node *current)
{
    if(current -> getLeft() != NULL) print(current->getLeft());
    if((current -> getData() == '+')||(current -> getData() == '-')||(current -> getData() == '*')||(current -> getData() == '%')||(current -> getData() == '/')||(current -> getData() == '^')||(current -> getData() == '#'))
    {
        cout << current -> getData();
    }else
    {
        if(current -> getValue() < 0)
            cout << "(" << current -> getValue() << ")";
        else
            cout << current -> getValue();
    }
    if(current -> getRight() != NULL) print(current->getRight());
}

void ETree::evaluate(Node *current)
{
    if(current -> getData() == '!')
    {
        if((current -> getLeft() -> getData()) ==0)
        {
            current -> setValue(1);
        }else
        {
            int x = current-> getLeft() -> getValue();
            int y = current-> getLeft() -> getValue();
            for(int i = 0; i < current -> getLeft() -> getValue(); i++)
            {
                y*=x;
                x--;
            }
            current -> setValue(x);
        }
    }
    if(current -> getData() == '#')
    {
        if((int(current -> getLeft() -> getValue())%2) == 0)
            current -> setValue(((current -> getLeft() -> getValue())-(current -> getRight() -> getValue())) * (current -> getLeft() -> getValue()));
        else
            current -> setValue(((current -> getLeft() -> getValue())-(current -> getRight() -> getValue())) * (current -> getRight() -> getValue()));
    }
    if(current -> getData() == '+')
        current -> setValue((current -> getLeft() -> getValue())+(current -> getRight() -> getValue()));
    if(current -> getData() == '-')
        current -> setValue((current -> getLeft() -> getValue())-(current -> getRight() -> getValue()));
    if(current -> getData() == '*')
        current -> setValue((current -> getLeft() -> getValue())*(current -> getRight() -> getValue()));
    if(current -> getData() == '%')
    {
        if(current -> getRight() -> getValue() == 0)
        {
            //cout << "Error: DIVIDE BY 0 (Answer Invalid)" << endl;
            a=1;
            current -> getRight() -> setValue(0);// setValue(0);
        }else
        {
            current -> setValue((int(current -> getLeft() -> getValue()))%(int(current -> getRight() -> getValue())));
        }
    }
    if(current -> getData() == '^')
    {
        if(((current -> getLeft() -> getValue())!=0)&&((current -> getRight() -> getValue())==0))
        {
            current -> setValue(1);
        }else if(((current -> getLeft() -> getValue())==0)&&((current -> getRight() -> getValue())==0))
        {
            //cout << "Error: INDETERMINATE FORM (Answer Invalid)" << endl << endl;
            a=1;
            current -> setValue(0);
        }else if(((current -> getLeft() -> getValue())==0)&&((current -> getRight() -> getValue())<0))
        {
            //cout << "Error: UNDEFINED (Answer Invalid)" << endl;
            a=1;
            current -> setValue(0);
        }else if(current -> getRight() -> getValue() > 0)
        {
            double x = 1;
            for(int i = 0; i < current -> getRight() -> getValue(); i++)
                x*= current -> getLeft() -> getValue();
            current -> setValue(x);
        }else if(current -> getRight() -> getValue() < 0)
        {
            double x = 1;
            for(int i = 0; i < (current -> getRight() -> getValue())*-1; i++)
                x*= current -> getLeft() -> getValue();
            current -> setValue(double(1/x));
        }
    }
    if(current -> getData() == '/')
    {
        if((current -> getRight()-> getValue()) == 0)
        {
            //cout << "Error: DIVIDE BY 0 (Answer Invalid)" << endl;
            a=1;
            current -> getRight() -> setValue(0);
        }
        current -> setValue(double(((current -> getLeft() -> getValue()))/(current -> getRight() -> getValue())));
    }
}

void ETree::execute()
{
    string input;
    cin >> input;
    if((input[0])=='!')
    {
        input.erase(0,1);
        int x = (input[0] - '0')-1;
        //cout << "X: " << x << endl;
        int y = (input[0] - '0');
        int z = x;
        for(int i = 0; i < z; i++)
        {
            y*=(x);
            x--;
        }
        cout <<  y << endl;
    }else{
    a=0;
    insert(input, root);
    if(a == 1)
        cout << "Error " << endl;
    if(a == 0)
        cout << root -> getValue() << endl;
    print(root);
    }
}

int main()
{
    for(int z = 0; z < 1; z++)
    {
        ETree t;
        t.execute();
        cout << endl << endl;
    }
    return 0;
}
