/******************************************************************************

Print Function has been copied from geeks for geeks.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createnewnode(int data)
{
    Node* temp = NULL;
    temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void create_diamond_tree(queue<Node*> q, int level)
{
    int height = level - 1;
    int num = 1;
    while(height --)
    {
        int qsize = q.size();
        while(qsize--)
        {
            Node* tmp = q.front();
            q.pop();
            
            tmp->left = createnewnode(++num);
            tmp->right = createnewnode(++num);
            
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
    
    while(q.size() > 1)
    {
        Node* left = q.front();
        q.pop();
        Node* right = q.front();
        q.pop();
        
        left->right = createnewnode(left->data + right->data);
        right->left = left->right;
        
        q.push(left->right);
    }
}
void printLevelOrder(Node* root, int k) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // Create an empty queue 
    queue<Node*> qu; 
  
    qu.push(root); 
    int level = k - 1; 
  

    while (level--) { 
  
        int qsize = qu.size(); 
        while (qsize--) { 
  
            Node* temp = qu.front(); 
            qu.pop(); 
            cout << temp->data << " "; 
  
            // Enqueue left child 
            if (temp->left != NULL) 
                qu.push(temp->left); 
  
            // Enqueue right child 
            if (temp->right != NULL) 
                qu.push(temp->right); 
        } 
        cout << endl; 
    } 
  

    while (qu.size() > 1) { 
  
        int qsize = qu.size(); 
        while (qsize) { 
  
            Node* first = qu.front(); 
            qu.pop(); 
            Node* second = qu.front(); 
            qu.pop(); 
            cout << first->data << " "
                 << second->data << " "; 
            qu.push(first->right); 
            qsize = qsize - 2; 
        } 
        cout << endl; 
    } 
  
    // Print the last element 
    Node* first = qu.front(); 
    qu.pop(); 
    cout << first->data << endl; 
}

void create_structure(int level)
{
    queue<Node*> q;
    Node* root = createnewnode(1);
    q.push(root);
    create_diamond_tree(q, level);
    printLevelOrder(root, level);
}
int main()
{
    cout<<"Enter Number of Level for a diamond tree.";
    int level;
    cin>>level;
    
    if(level >= 1)
        create_structure(level);
    else
        cout<<"Wrong choice";
}