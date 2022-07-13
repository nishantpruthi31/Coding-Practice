                                         /* implementing Queue using linked list */

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};
struct node *front=0;  // to handle deletion
struct node *rear=0;   // to handle insertion

void enqueue(int x)
{
    struct node *newnode=new (struct node);
    newnode->data=x;
    newnode->link=0;
    if(front==0 && rear==0)    // if queue is empty
    {
        front=rear=newnode;
    }
    else
    {
        rear->link=newnode;
        rear=newnode;
    }
}
void dequeue()
{
 if(front==0 && rear==0)                // Queue is empty
 cout<<"Underflow"<<endl;
 else
 {
     struct node *temp;
     temp=front;
     
     front=front->link;
     free(temp);                      // freeing the memory 
 }         
}
void peek()                
{
    if(front==0 && rear==0)              // empty Queue
    cout<<"Queue is empty"<<endl;
    else
    cout<<"Top element is:"<<front->data<<endl;
}
void display()                       // to display all elements
{
    if(front==0 && rear==0)         // Queue is empty
    cout<<"Queue is empty"<<endl;
    else
    {
        struct node *temp;
        temp=front;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
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
