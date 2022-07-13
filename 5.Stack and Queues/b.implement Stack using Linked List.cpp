                                         /* implementing stack using linked list */

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *link;
};
struct node *top=0;  // to keep track of top most element of stack

void push(int x)
{
    struct node *newnode=new (struct node);
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}
void pop()
{
 if(top==0)                // stack is empty
 cout<<"Underflow"<<endl;
 else
 {
     struct node *temp;
     temp=top;
     
     top=top->link;
     free(temp);                      // freeing the memory 
 }         
}
void peek()                // to display top most element
{
    if(top==0)              // empty stack
    cout<<"Stack is empty"<<endl;
    else
    cout<<"Top element is:"<<top->data<<endl;
}
void display()  // to display all element from top to bottom
{
    if(top==0)         // stack is empty
    cout<<"Stack is empty"<<endl;
    else
    {
        struct node *temp;
        temp=top;
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
    // we have implemented 4 operations in stack :- push,pop,peek,display 
    push(1);
    push(2);
    display();
    pop();
    display();
    push(4);
    push(5);
    peek();
    push(7);
    display();
    return 0;
}
