#include<iostream>
#include<list>
#include<iterator>
#include <algorithm>
using namespace std;

typedef struct node
{
	int info;
	struct node *next; 
}node;

node * create(int n)
{
	node * nn = new node;
	nn->info = n;
	nn->next = NULL;
	
	return nn;
}

void findLoop(node * head, int &a, int &b)
{
	list<node *> ilist;
	list<node *>::iterator itr;
	while(head != NULL)
	{	
		itr = find(ilist.begin(), ilist.end(), head->next);
		if(itr != ilist.end())
		{
			//node *trav = *itr;
			a = (*itr)->info;
			b = head->info;
			break;
		}
		ilist.push_back(head);
		head = head->next;
	}
}

int main(void)
{
	node *ll = NULL;
	ll = create(5);
	ll->next = create(4);
	ll->next->next  = create (6);
	ll->next->next->next = create(7);
	ll->next->next->next = ll;
	
	int a = -1, b = -1;
	
	findLoop(ll, a, b);
	
	if(a == -1 && b == -1)
		cout << "No loop\n";
	else
		cout << a << " " << b << endl;
	
	return 0;
}
