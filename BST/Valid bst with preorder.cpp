#include <iostream>
using namespace std;

class node
{
    public:
        int info;
        node * left;
        node * right;
        node(int data)
        {
            info = data;
            left = right = NULL;
        }
};

node * insert(node * root, int data)
{
    if(root == NULL)
        return new node(data);
    else if(data < root->info)
    {
        root->left = insert(root->left, data);
        return root;
    }
    else
    {
        root->right = insert(root->right, data);
        return root;
    }
}

int preorder(node * root, int a[], int index)
{
    if(root == NULL)
        return index;
    
    //cout << root->info << " ";
    //cout << index << " ";
    
    a[index] = root->info;
    index++;
    index = preorder(root->left, a, index);
    index = preorder(root->right, a, index);
    return index;
}

int main()
{
    node * root = NULL;
    int arr[100], a[100];
    int n, k, l, flag, index;
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        root = NULL;
        index = 0;
        flag = 0;
        for(int j=0; j<k; j++)
        {
            cin >> l;
            arr[j] = l;
            root = insert(root, l);
        }
        
        index = preorder(root, a, index);
        
        for(int j=0; j<k; j++)
        {
            if(arr[j] != a[j])
            {
                flag = 1;
                cout << "NO";
                break;
            }
        }
        
        if(flag == 0)
            cout << "YES";

        cout << endl;
    }

    return 0;
}
