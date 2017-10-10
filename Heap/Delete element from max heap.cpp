#include <iostream>
#include <array>
using namespace std;

void maxheapify(int a[], int i, int n)
{
    //if leaf nodes are coming then go back
    if(i > n/2 - 1)
        return;

    int lchild = i * 2 + 1;
    int rchild = i * 2 + 2;
    if(a[lchild] > a[rchild] && a[lchild] > a[i])
    {
        swap(a[lchild], a[i]);
        //maintain subtree also because after swaping subtree maxheap propertie is not maintained
        maxheapify(a, lchild, n);
    }
    else if(a[rchild] > a[lchild] && a[rchild] > a[i])
    {
        swap(a[rchild], a[i]);
        //maintain subtree also because after swaping subtree maxheap propertie is not maintained
        maxheapify(a, rchild, n);
    }
}

void maxheap(int a[], int n)
{
    //from last parent to root
    for(int i=n/2 - 1; i>=0; i--)
        maxheapify(a, i, n);
}

int main()
{
    int a[] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 18, 20, 1, 24};
    int n = sizeof(a) / sizeof(int);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
        cout << endl;

    maxheap(a, n);;

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
        cout << endl;

    //after heap sort array is {84 22 24 10 20 19 6 5 9 18 3 1 17}
    //delete 24;
    a[2] = a[n-1];

    maxheapify(a, 2, n);

    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
        cout << endl;
    return 0;
}
