
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int temp)
{
    if(s.size()==0 || temp>=s.top())
    {
        s.push(temp);
        return ;
    }
    
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}

void sort(stack<int> &s)
{
    if(s.size()==1)
    return ;
    
    int val=s.top();
    s.pop();
    sort(s);
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
sort(s);

while(s.empty()==false)
{
   int x=s.top();
   s.pop();
   cout<<x<<" ";
}
return 0;
}