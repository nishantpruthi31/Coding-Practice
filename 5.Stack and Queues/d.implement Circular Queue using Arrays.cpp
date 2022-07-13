                                         /* implementing  circular Queue using array */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define n 5
int Queue[n];
int front=-1;
int rear=-1;

void enqueue(int x)           
{
     if(front==-1 && rear==-1)         
    {
        front=rear=0;
        Queue[rear]=x;
    }
   else if(((rear+1)%n)==front)                   // overflow condition
    {
        cout<<"overflow"<<endl;
    }
    
    else
    {
        rear=(rear+1)%n;                          // thiw is how we incrrment rear
        Queue[rear]=x;
    }
}
void dequeue()              
{
    if(front==-1 && rear==-1)              
    {
        cout<<"underflow"<<endl;
    }
    else if(front==rear)                       
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%n;                // this is how we increment front
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)                  
    {
        cout<<"empty"<<endl;
    }
    else
    {
        int i=front;     // traversing 
        while(i!=rear)
        {
            cout<<Queue[i]<<" ";
            i=(i+1)%n;
        }
        cout<<Queue[rear] <<endl;             // to print last element as while didn't get there
       
    }
}
void peek()
{
    if(front==-1 && rear==-1)                     
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"top elment is:"<<Queue[front]<<endl;
    }
}

int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(3);
    enqueue(1);
    enqueue(8);
    peek();
    display();
    dequeue();
    dequeue();
    enqueue(2);
    display();
    return 0;
}