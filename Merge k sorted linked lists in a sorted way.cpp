#include<iostream>
using namespace std;
#include<bits/stdc++.h>

struct Node
{
	int data;
	Node* next;	
};

void push(Node** head, int newdata)
{
  Node* newnode = new Node;
  newnode -> data = newdata;
  newnode -> next = *head;
  *head = newnode;
}

Node* result=NULL;

void Sort(Node* one , Node* two)
{  
    Node* temp;
    result = one;
    temp = result;

     if(one->data<two->data)
	          {
		        result = one;
		        one = one->next;
		        temp= result;
	           }
   
	  else
	           {
		          result = two;
		          two = two->next;
		          temp = result;
	           }

	while(one!=NULL&&two!=NULL)
	{
	     
	    if(one->data<two->data)
	        {
	     	    temp->next= one;
	     	    temp = one;
	     	    one = one->next;
   
	         }
	     else
	        {
	     	    temp->next= two;
	     	    temp = two;
	     	    two = two->next;
	        }
 
     }

   
          if (one ==NULL)
          {
          	temp->next = two;
          	
          }      

          else if (two == NULL)

          {
          	temp->next = one;
          	
          }
       
}



int main() 
{
	int k=3;
	
	
	Node* arr[3];

	for(int j = 0;j<k;j++)
	{
		arr[j] = NULL;
 	}
	

	
	push(&arr[0],7);
	push(&arr[0],5);
	push(&arr[0],3);
	push(&arr[0],1);
	
	push(&arr[1],8);
	push(&arr[1],6);
	push(&arr[1],4);
	push(&arr[1],2);

	push(&arr[2],11);
	push(&arr[2],10);
	push(&arr[2],9);
	push(&arr[2],0);

    Sort(arr[0],arr[1]);
   


    for(int i=2;i<k;i++)
	{
		Sort(result,arr[i]);
	}

    

  	Node* temp = result;
    while(temp!=NULL)
    {
    	cout<<temp->data<<" ";
    	temp=temp->next;
    }
	
   

  return 0;
}
