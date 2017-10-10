#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node * left;
        node * right;
		
        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node * insert(node * root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }
    
    node * ptr = root;
    
    while(1)
    {
        if(ptr->data > data)
        {
            if(ptr->left != NULL)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr->left = new node(data);
                break;
            }
        }
        else if(ptr->data < data)
        {
            if(ptr->right != NULL)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr->right = new node(data);
                break;
            }
        }
    }
    
    return root;
}

int main()
{
    node * root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 2);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 7);
    
    return 0;
}
