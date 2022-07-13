
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


void solve(stack<int> &s,int k)
{
    if(k==1)
    {
     s.pop();
     return ;
    }
    int val=s.top();
    s.pop();
    solve(s,k-1);
    s.push(val);
}

int main()
{
stack<int> s;    // vector<int> arr={1,7,2,5,6};
s.push(1);
s.push(7);
s.push(2);
s.push(5);
s.push(6); 
int k=(s.size()/2)+1; // suppose n is 5 middle element is 3, n is 6 middle is 4
//cout<<k;
solve(s,k);

while(s.empty()==false)
{
   int x=s.top();
   s.pop();
   cout<<x<<" ";
}
return 0;
}