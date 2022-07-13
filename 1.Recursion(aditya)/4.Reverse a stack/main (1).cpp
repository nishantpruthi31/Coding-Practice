
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
void insert(stack<int> &s,int val)
{
    if(s.size()==0)
    {
    s.push(val);
    return ;
    }
    int temp=s.top();
    s.pop();
    insert(s,val);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if(s.size()==1)
    {
     return ;
    }
    int val=s.top();
    s.pop();
    reverse(s);
    insert(s,val);
}



int main()
{
stack<int> s;    // vector<int> arr={1,7,2,5,6};
s.push(1);
s.push(7);
s.push(2);
s.push(5);
s.push(6); 
 
reverse(s);

while(s.empty()==false)
{
   int x=s.top();
   s.pop();
   cout<<x<<" ";
}
return 0;
}