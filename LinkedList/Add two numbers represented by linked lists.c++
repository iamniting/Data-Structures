#include <iostream>
using namespace std;

class node
{
    public:
    int info;
    node * next;
    node(int n)
    {
        this->info = n;
        this->next = NULL;
    }
};

node * create(node * head, int n)
{
    node * nn = new node(n);
    nn->next = head;
    head = nn;
    return head;
}

node * AddLists(node * head1, node * head2)
{
    node * res = NULL;
    bool carry = 0;
    while(head1 != NULL || head2 != NULL)
    {
        int s = 0;
        if(head1 != NULL)
        {
            s = head1->info;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            s = s + head2->info;
            head2 = head2->next;
        }
        
        if(carry == 1)
        {
            s = s + 1;
        }
        
        if(s > 9)
        {
            carry = 1;
            s = s % 10;
            res = create(res, s);
        }
        else
        {
            carry = 0;
            res = create (res, s);
        }
    }
    if(carry == 1)
    {
        res = create(res, 1);
    }
    return res;
}

int main() 
{
    int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    node * head1 = NULL;
	    node * head2 = NULL;
	    node * res = NULL;
	    for(int j=0; j<n1; j++)
	    {
	        int a;
	        cin >> a;
	        head1 = create(head1, a);
	    }
	    for(int j=0; j<n2; j++)
	    {
	        int a;
	        cin >> a;
	        head2 = create(head2, a);
	    }
	    /*res = head1;
	    while(res != NULL)
	    {
	        cout << res->info << " ";
	        res = res->next;
	    }
	    res = head2;
	    while(res != NULL)
	    {
	        cout << res->info << " ";
	        res = res->next;
	    }
	    res = NULL;*/
	    res = AddLists(head1, head2);
	    
	    while(res != NULL)
	    {
	        cout << res->info << " ";
	        res = res->next;
	    }
	    cout << endl;
	}
	return 0;
}
