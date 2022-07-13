                                         /* implementing stack using arrays */

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define n 5
int Stack[n];
int top=-1;  // to keep track of top most element of stack

void push(int x)
{
    if(top==n-1)            // stack is full
    cout<<"Overflow"<<endl;
    else
    {
        top++;
        Stack[top]=x;
    }
}
void pop()
{
 if(top==-1)                // stack is empty
 cout<<"Underflow"<<endl;
 else
 top--;                            // value at top will be overwridden later
}
void peek()                // to display top most element
{
    if(top==-1)              // empty stack
    cout<<"Stack is empty"<<endl;
    else
    cout<<"Top element is:"<<Stack[top]<<endl;
}
void display()  // to display all element from top to bottom
{
    for(int i=top;i>=0;i--)
    {
        cout<<Stack[i]<<" ";
    }
    cout<<endl;
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
