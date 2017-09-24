#include <iostream>
#include <unordered_set>
using namespace std;

class node
{
    public:
    int n;
    node * next;
    node(int n)
    {
        this->n = n;
        this->next = NULL;
    }
};

node * newnode(int key)
{
    node * temp = new node(key);
    return temp;
}

node * create(node * head, int key)
{
    if(head == NULL)
    {
        head = new node(key);
        return head;
    }
    else
    {
        node * temp = new node(key);
        temp->next = head;
        head = temp;
        return head;
    }
}

void printreverselist(node * head)
{
    if(head == NULL)
        return;
    printreverselist(head->next);
    cout << head->n << " ";
}

void printlist(node *head)
{
    while(head != NULL)
    {
        cout << head->n << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node * head = NULL;
    for(int i=0; i<8; i++)
    {
        head = create(head,i);
    }
    printlist(head);
    printreverselist(head);
}
