#include <iostream>
using namespace std;
#include<bits/stdc++.h>

struct Node
{
    long long int data;
    Node* left;
    Node* right;
    long long int key;
};
long long int key;
Node* getnewnode(long long int newdata,long long int key)
{
    Node* newnode = new Node;
    newnode->data = newdata;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->key = key;
    return newnode;
}

Node* Insert(Node* root,long long int data,long long int key)
{
    if(root==NULL)
    {
        root = getnewnode(data,key);
        cout<<root->key;
        cout<<"\n";
    }
    
    else if(root->data >= data)
    {
        key=2*key;
        root->left = Insert(root->left,data,key);
        
    }
    else
    {
       key=2*key+1;
       root->right = Insert(root->right,data,key); 
    }
    
    return root;
}

Node* search(Node* root, long long int value)
{
    if (root==NULL) return root;
    if (root->data>value) return search(root->left,value);
    else if (root->data<value) return search(root->right,value);
    else
    {
        return root;
    }
}

Node* findmin(Node* root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

void adjustkeys(Node* root)
{
    int p = root->key;
    while(root->left!=NULL ||root->right!==NULL)
    {
        if(root->left!=NULL) 
        {
            root->left->key = 2*p;
            adjustkeys(root->left);
        }
        if(root->right!=NULL)
        {
            root->right->key =2*p+1;
            adjustkeys(root->right);
    }
    return;
}

Node* del(Node* root ,long long int value)
{
    if (root==NULL) return root;
    Node*temp = search(root,value);
    if(temp==NULL) return root;
    if(temp->data >root->data) root->right = del(root->right,x);
    else if ( temp->data < root->data) root->left = del(root->left,x);
    else 
    {
        //no child 
        if(root->left==NULL && root->right==NULL)
        {
            Node* temp= root;
            delete root;
            return NULL;
        }
        //one child
        else if(root->left==NULL )
        {
            Node* temp= root;
            temp->right->key = root->key;
            adjustkeys(root->right);
            temp = temp->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp= root;
            temp->left->key = root->key;
            adjustkeys(root->left);
            temp=temp->left;
            delete root;
            return temp;
        }
        //two child
        else if(root->left!=NULL && root->right!=NULL)
        {
            Node* min = findmin(root->right);
            root->data = min->data;
            root->right = del(root->right,min->data);
            return root;
        }
    }
    return root;
    
    
    
}

Node* deletex(Node* root,long long int x)
{ 
    if (root==NULL) return root;
    Node*temp = search(root,x);
    if(temp->data >root->data) root->right = deletex(root->right,x);
    else if ( temp->data < root->data) root->left = deletex(root->left,x);
    else 
    {
        //no child 
        if(root->left==NULL && root->right==NULL)
        {
            Node* temp= root;
            cout<<root->key<<"\n";
            delete root;
            return NULL;
        }
        //one child
        else if(root->left==NULL )
        {
            Node* temp= root;
            temp->right->key = root->key;
            adjustkeys(root->right);
            cout<<root->key<<"\n";
            temp = temp->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp= root;
            temp->left->key = root->key;
            adjustkeys(root->left);
            cout<<root->key<<"\n";
            temp=temp->left;
            delete root;
            return temp;
        }
        //two child
        else if(root->left!=NULL && root->right!=NULL)
        {
            Node* min = findmin(root->right);
            root->data = min->data;
            root->right = del(root->right,min->data);
            return root;
        }
    }
    return root;
    
}

int main() 
{
  key=1;
  Node* root= NULL;
  int q;
  long long int x;
  char op;
  cin>>q;
  for(int j=0;j<q;j++)
  {
      cin>>op;
      cin>>x;
      
      if (op=='i')
      {
        root = Insert(root,x,key);  
      }
      else if (op=='d')
      {
        root = deletex(root,x);  
      }
      
  }
  
	// your code goes here
	return 0;
}
