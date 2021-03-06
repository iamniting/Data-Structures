#include <iostream>
#include <queue>
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

int get_height(node * root)
{
    if(root == NULL)
        return -1;
		
    queue <node *> q;
    int height = -1;
    
    q.push(root);
    
    // add null as marker of level
    
    q.push(NULL);
    
    while(!q.empty())
    {
        node * temp = q.front();
        q.pop();
        
        /* check if temp is null, if yes, we have reached to the end of the
        current level, increment the height by 1, and add the another
        null as marker for next level */
        
        if(temp == NULL)
        {
            height++;
            
            /* before adding null, check if queue is empty, which means we
            have traveled all the levels */
            
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return height;
}

int calculate_height(node * root)
{
    if(root == NULL)
        return -1;
    
    int height = -1;
    
    queue <node *> q;
    q.push(root);
    
    while(!q.empty())
    {
        // nodeCount indicates no. of nodes at current level
        
        int nodeCount = q.size();
        height++;
        
        // dequeue all nodes of current level
        // enqueue all child nodes of the current level
        
        for(int i=0; i<nodeCount; i++)
        {
            node * temp = q.front();
            q.pop();
            
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    return height;	
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
    
    // get_height function with time complexity of big O (n)
    cout << endl << "height is " << get_height(root);
    
    // calculate_height function with time complexity of big O (n ^ 2)
    cout << endl << "height is " << calculate_height(root);
    
    return 0;
}
