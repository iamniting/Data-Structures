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

void printList(node *head)
{
    while(head != NULL)
    {
        cout << head->n << " ";
        head = head->next;
    }
    cout << endl;
}

void removeloop(node * head)
{
    unordered_set<node *> s;
    node * save = head;
    
    while(head)
    {
        if(s.find(head) == s.end())
        {
            s.insert(head);
        }
        else
        {
            save->next = NULL;
            break;
        }
        save = head;
        head = head->next;
    }
}

void findloop(node * head)
{
    if(head == NULL)
        return;
    node * sptr = head;
    node * fptr = head;
    
    sptr = sptr->next;
    fptr = fptr->next->next;
    
    while(fptr && fptr->next)
    {
        if(sptr == fptr)
        {
            removeloop(head);
            break;
        }
        sptr = sptr->next;
        fptr = fptr->next->next;
    }
}

int main()
{
    node * head = NULL;
    head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(5);
    head->next->next->next->next->next = newnode(6);
    head->next->next->next->next->next->next = newnode(7);
    head->next->next->next->next->next->next->next = newnode(8);
    
    head->next->next->next->next->next->next->next->next = head->next;
    //head->next = head;
    findloop(head);
    printList(head);
}
