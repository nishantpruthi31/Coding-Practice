                                         /* implementing Circular Queue(circular linked list) using linked list */

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};
struct node *front=0;  
struct node *rear=0;   

void enqueue(int x)
{
    struct node *newnode=new (struct node);
    newnode->data=x;
    newnode->link=0;
    if(front==0 && rear==0)    
    {
        front=rear=newnode;
        rear->link=front;                  // node pointing to itself as only 1 node
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
        rear->link=front;                          // node pointing to front
    }
}
void dequeue()
{
   struct node *temp;
   temp=front;
 if(front==0 && rear==0)                
 cout<<"Underflow"<<endl;
 else if(front==rear)                  // only 1 node
 {
    front=rear=0;
    free(temp);
 }
 else
 {
     front=front->link;
     rear->link=front;            // updating last node to first
     free(temp);                    
 }         
}
void peek()                
{
    if(front==0 && rear==0)              
    cout<<"Queue is empty"<<endl;
    else
    cout<<"Top element is:"<<front->data<<endl;
}
void display()                       
{
    if(front==0 && rear==0)         
    cout<<"Queue is empty"<<endl;
    else
    {
        struct node *temp;
        temp=front;
        while(temp->link!=front)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<temp->data<<endl;  // to print last node
    }
}
int main()
{
    enqueue(5);
    enqueue(0);
    enqueue(3);
    display();
    dequeue();
    peek();
    display();
    return 0;
}
