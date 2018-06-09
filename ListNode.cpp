#include <iostream>

using namespace std;

class ListNode
{
private:
    int data;
    ListNode *next;
public:
    ListNode(int d, ListNode *n){data = d;next = n;}
    int getData(){return (data);}
    ListNode* getNext(){return next;}
    void setNext(ListNode *n){next = n;}
};

class List
{
private:
    ListNode *first;
public:
    List()
    {
        first = NULL;
    }
    void menu();
    void insert(int &x);
    void print();
    void remove(int &x);
};

void List::insert(int &n)
{
    //int n = 0;
    //cin >> n;
    if(first == NULL)
    {
        first = new ListNode(n,NULL);
    }else
    {
        ListNode *current = first;
        if(n < (first -> getData()))
        {
            first = new ListNode(n, first);
        }else
        {
            while((current -> getNext() != NULL)&&(current->getNext()->getData() < n))
            {
                current = current->getNext();
            }
            current->setNext(new ListNode(n, current->getNext()));
        }
    }cout << endl;
}

void List::print()
{
    if(first == NULL)
    {
        cout << "No List" << endl;
    }else
    {
        ListNode *current = first;
        while(current != NULL)
        {
            cout << current -> getData() << "  ";
            current = current -> getNext();
        }cout << endl;
    }
}

void List::remove(int &n)
{
    //int n = 0;
    //cin >> n;
    if(first == NULL)
    {
        cout << "No List" << endl;
    }else
    {
        if(n == first->getData())
        {
            first = first->getNext();
        }else
        {
            ListNode *current = first;
            while((current -> getNext() != NULL)&&(current->getNext()->getData() != n))
            {
                current = current->getNext();
            }
            if(current->getNext() == NULL)
            {
                cout << "Not in List" << endl;
            }else
            {
                if(current->getNext()->getData() == n)
                {
                    current->setNext(current->getNext()->getNext());
                }
            }
        }
    }
}

void List::menu()
{

    int choice = 0;
    int x = 0;
    while (choice != 4)
    {
        cout << "This is the Menu. 1) Insert  2)Print  3) Delete  4) Exit  :   " ;
        cin >> choice;
        if(choice == 1)
        {
            cout << "INSERT INTEGER: ";
            cin >> x;
            insert(x);
        }else if(choice == 2)
        {
            cout << "PRINT" << endl;
            print();
        }else if(choice == 3)
        {
            cout << "DELETE INTEGER: ";
            cin >> x;
            remove(x);
        }
    }
}



int main()
{
    List l;
    l.menu();
    return 0;
}
