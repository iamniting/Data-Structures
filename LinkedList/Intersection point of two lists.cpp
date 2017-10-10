#include <iostream>
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

void printlist(node *head)
{
    while(head != NULL)
    {
        cout << head->n << " ";
        head = head->next;
    }
    cout << endl;
}

void intersectionPoint(node * head1, node * head2)
{
    if(head1 == head2)
    {
        cout << head1->n << " " << head1 << endl;
        cout << head2->n << " " << head2 << endl;
        return;
    }
    int c1 = 0, c2 = 0, dis;
    node * h1 = head1, * h2 = head2;
    node * last1, * last2;

    // count the elements in list
    while(head1 || head2)
    {
        if(head1 != NULL)
        {
            c1++;
            last1 = head1;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            c2++;
            last2 = head2;
            head2 = head2->next;
        }
    }
    
    //there is intersection Point in list
    if(last1 == last2)
    {
        if(c1 > c2)
        {
            dis = c1 - c2;
            while(dis--)
                h1 = h1->next;
        }
        else
        {
            dis = c2 - c1;
            while(dis--)
                h2 = h2->next;
        }
        while(h1 != h2)
        {
            if(h1->next == h2->next)
            {
                cout << h1->next->n << " " << h1->next << endl;
                cout << h2->next->n << " " << h2->next << endl;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
    }
}

int main()
{
    node * head1 = NULL;
    node * head2 = NULL;
    for(int i=0; i<8; i++)
    {
        head1 = create(head1,i);
    }

    for(int i=9; i<12; i++)
    {
        head2 = create(head2,i);
    }
    printlist(head1);
    printlist(head2);

    //join two lists
    head2->next->next->next = head1->next->next->next->next->next;

    printlist(head1);
    printlist(head2);
    intersectionPoint(head1, head2);
    //intersectionPoint(head1, head1);
}
