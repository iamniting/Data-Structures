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

void nthNoFromLast(node * head, int n)
{
    node * fptr = head;
    node * sptr = head;
    int c = 0;
    while(fptr != NULL)
    {
        fptr = fptr->next;
        c++;
        if(c > n)
        sptr = sptr->next;
    }
    cout << sptr->info;
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
    nthNoFromLast(head, 1);
    
    return 0;
}
