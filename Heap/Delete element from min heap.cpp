#include <iostream>
#include <array>
using namespace std;

void minheapify(int a[], int i, int n)
{
    //if leaf nodes are coming then go back
    if(i > n/2 - 1)
        return;

    int lchild = i * 2 + 1;
    int rchild = i * 2 + 2;
    if(a[lchild] < a[rchild] && a[lchild] < a[i])
    {
        swap(a[lchild], a[i]);
        //maintain subtree also because after swaping subtree minheap propertie is not maintained
        minheapify(a, lchild, n);
    }
    else if(a[rchild] < a[lchild] && a[rchild] < a[i])
    {
        swap(a[rchild], a[i]);
        //maintain subtree also because after swaping subtree minheap propertie is not maintained
        minheapify(a, rchild, n);
    }
}

void minheap(int a[], int n)
{
    //from last parent to root
    for(int i=n/2 - 1; i>=0; i--)
        minheapify(a, i, n);
}

int main()
{
    // how many parents (n/2)
    // how many leafs (n/2)
    // last parent (n/2) - 1
    // first leaf (n/2) + 1

    int a[] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 18, 20, 1, 24};
    int n = sizeof(a) / sizeof(int);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
        cout << endl;

    minheap(a, n);;

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
        cout << endl;

    //after heap sort array is {1 3 5 9 18 17 6 22 10 84 20 19 24}
    //delete 3
    a[1] = a[n-1];

    minheapify(a, 1, n);

    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
        cout << endl;
    return 0;
}
