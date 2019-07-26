#include<iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

struct Node
{
  int data;
  Node* next;
};

Node*a, *b;

void push(Node** head, int newdata)
{
  Node* newnode = new Node;
  newnode -> data = newdata;
  newnode -> next = *head;
  *head = newnode;
}

int carry=0;

Node* sumx(int op1 , int op2 )
{ 
  int s = op1 + op2 + carry;
  Node* newnode = new Node;
  newnode->next = NULL;
  if(s>9)
  {
    newnode->data = (s - 10);
    carry = 1;
  }
  else
  {
    newnode->data = s;
    carry = 0;
  }
  return newnode;
}

Node* reversell(Node** head)
{
  Node* temp, *prev,*curr;
  temp = *head;
  while(temp!=NULL)
  {
    if (temp==*head)
    {
      curr = temp->next;
      prev = temp;
      temp->next = NULL;
      temp = curr;
    }

    else
    {
      curr = temp->next;
      temp->next = prev;
      prev = temp;
      temp = curr;
    }
  }

  *head = prev;
  return *head;
}

void sum(Node*one, Node*two)
{
  Node* res=NULL;
  Node* temp,*curr;
  while(one->next!=NULL&&two->next!=NULL)
  {
    temp = sumx(one->data , two->data);
    if(res == NULL) 
    {
      res = temp;
    }
    else
    {
      curr->next = temp;
    }
    curr = temp;
    one = one->next;
    two = two->next;  
  }

  int s = one->data + two->data + carry;
   
  Node* newnode = new Node;
  newnode->next = NULL; 
  if(s>9)
  {
     newnode->data = s - 10;
     curr->next = newnode;
     curr = newnode;
     carry = 1;
  }

  else
  {
    newnode->data = s ;
    curr->next =newnode;
    curr = newnode;
    carry =0;
  }

  if(one->next==NULL && two->next!=NULL)
  { two = two->next;
    while(two!=NULL)
      {
          temp = sumx(two->data, 0);
          curr->next = temp;
          curr = temp;
          two = two->next;
      }
      
      if(carry)
      {
        Node* last = new Node;
        last->data = 1;
        last->next=NULL;
        curr->next = last;
        curr = last;
      }    
  }

  else if(one->next!=NULL && two->next==NULL)
  {
     one = one->next;
     while(one!=NULL)
      {
          temp = sumx(one->data, 0 );
          curr->next = temp;
          curr = temp;
          one = one->next;
      }
      
      if(carry)
      {
        Node* last = new Node;
        last->data = 1;
        last->next=NULL;
        curr->next = last;
        curr = last;
      }    
  }

  if(carry)
      {
        Node* last = new Node;
        last->data = 1;
        last->next=NULL;
        curr->next = last;
        curr = last;
      }    

    

res = reversell(&res);
Node* tempor = res;
while(tempor!=NULL)
{
  cout<<tempor->data<<" ";
  tempor= tempor->next;
}
}



int main()
{
  a=NULL;
  b=NULL;
  //push(&a,3);
  push(&a,6);
  push(&a,5);

   push(&b,2);
  push(&b,4);
  push(&b,8);
  
  a = reversell(&a);
  b = reversell(&b);

 sum(a,b);
  
}
