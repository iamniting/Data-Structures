#include <iostream>
using namespace std;

class node
{
    public:
    int info;
    node * next;
};

node * create(node * head, int n)
{
    if(head == NULL)
    {
        node * nn = new node;
        nn->info = n;
        nn->next = NULL;
        return nn;
    }
    else
    {
        node * nn = new node;
        nn->info = n;
        nn->next = head;
        return nn;
    }
}

void print(node * head)
{
    while(head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
}

void middleOfList(node * head)#include <iostream>
using namespace std;

class node
{
    public:
    int info;
    node * next;
};

node * create(node * head, int n)
{
    if(head == NULL)
    {
        node * nn = new node;
        nn->info = n;
        nn->next = NULL;
        return nn;
    }
    else
    {
        node * nn = new node;
        nn->info = n;
        nn->next = head;
        return nn;
    }
}

void print(node * head)
{
    while(head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
}

void middleOfList(node * head)
{
    node * fptr = head;
    node * sptr = head;
    node * prev = head;
    
    while(fptr && fptr->next)
    {       
        fptr = fptr->next->next;
        prev = sptr;
        sptr = sptr->next;
    }
    
    cout << prev->info;
}

int main()
{
    node * head = NULL;
    
    for(int i=1; i<6; i++)
    {
        head = create(head, i);
    }
    
    print(head);
    cout << endl;
    middleOfList(head);
    
    return 0;
}

{
    node * fptr = head;
    node * sptr = head;
    node * prev = head;
    
    while(fptr && fptr->next)
    {       
        fptr = fptr->next->next;
        prev = sptr;
        sptr = sptr->next;
    }
    
    cout << prev->info;
}

int main()
{
    node * head = NULL;
    
    for(int i=1; i<3; i++)
    {
        head = create(head, i);
    }
    
    print(head);
    cout << endl;
    middleOfList(head);
    
    return 0;
}
