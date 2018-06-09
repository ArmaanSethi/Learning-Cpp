#include <iostream>
#include <string>

using namespace std;

int height = 0;

class Node
{
private:
    char data;
    Node *left;
    Node *right;
    int depth;
public:
    Node(char d, Node *l,Node *r, int p){data = d;left = l; right = r;depth = p;}
    char getData(){return (data);}
    int getDepth(){return(depth);}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    void setLeft(Node *n){left = n;}
    void setRight(Node *n){right = n;}
};

class Tree
{
private:
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }
    void execute();
    void insert(char &x);
    void print(Node *current);
};

void Tree::insert(char &n)
{
    int a = 0;
    if(root == NULL)
    {
        root = new Node(n,NULL, NULL, 0);
    }else
    {
        Node *current = root;
        if((current -> getLeft() == NULL)&&(n <= current -> getData()))
        {
            current -> setLeft(new Node(n,  NULL, NULL, (current->getDepth())+1));
        }else if((current -> getRight() == NULL)&&(n > current -> getData()))
        {
            current -> setRight(new Node(n, NULL, NULL,(current->getDepth())+1));
        }else
        {
            while((current -> getLeft() != NULL)||(current -> getRight() != NULL))
            {
                if(n > current -> getData())
                {
                    if((current -> getRight()) != NULL)
                    {
                        current = current -> getRight();
                    }
                    else
                    {
                        current -> setRight(new Node(n, NULL, NULL,(current->getDepth())+1));
                        current = current -> getRight();
                        a++;
                    }
                }else
                {
                    if((current -> getLeft()) != NULL)
                    {
                        current = current -> getLeft();
                    }
                    else
                    {
                        current -> setLeft(new Node(n,  NULL, NULL,(current->getDepth())+1));
                        current = current -> getLeft();
                        a++;
                    }
                }
            }
            cout << endl;
            if(a==0)
            {
                if(n > current -> getData())
                {
                    current -> setRight(new Node(n, NULL, NULL,(current->getDepth())+1));
                    current = current -> getRight();
                }else
                {
                    current -> setLeft(new Node(n,  NULL, NULL,(current->getDepth())+1));
                    current = current -> getLeft();
                }
            }
        }
    }
    cout << endl;
}

void Tree::print(Node *current)
{
    if(current -> getLeft() != NULL) print(current->getLeft());
    cout << current -> getData();
    if(current -> getDepth() > height) height = current -> getDepth();
    if(current -> getRight() != NULL) print(current->getRight());
}

void Tree::execute()
{
    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++)
    {
        insert(input[i]);
    }
    print(root);
    cout << "  " << height << endl;
}

int main()
{
    Tree t;
    t.execute();
    return 0;
}
