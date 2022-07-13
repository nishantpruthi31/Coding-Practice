                                         /* implementing Queue using array */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define n 5
int Queue[n];
int front=-1;
int rear=-1;

void enqueue(int x)           // push operation
{
    if(rear==n-1)       
    {
        cout<<"overflow"<<endl;
    }
    else if(front==-1 && rear==-1)         // Queue is empty
    {
        front=rear=0;
        Queue[rear]=x;
    }
    else
    {
        rear++;
        Queue[rear]=x;
    }
}
void dequeue()              // pop operation
{
    if(front==-1 && rear==-1)              // Queue is empty
    {
        cout<<"underflow"<<endl;
    }
    else if(front==rear)                       // only 1 element in Queue 
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)                  // Queue is empty
    {
        cout<<"empty"<<endl;
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            cout<<Queue[i]<<" ";
        }
       cout<< endl;
    }
}
void peek()
{
    if(front==-1 && rear==-1)                     // Queue is empty
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
    peek();
    display();
    dequeue();
    display();
    return 0;
}