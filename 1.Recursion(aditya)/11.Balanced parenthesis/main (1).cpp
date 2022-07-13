

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve (string op,int open,int close,vector<string> &v)
{
    if(open==0 && close==0)
    {
       v.push_back(op);
        return;
    }
    if(open!=0)        // open ki call hamesha milri
    {
        string op1=op;
        op1.push_back('(');
        solve(op1,open-1,close,v);
    }
   
   if(close>open)
   {
       string op2=op;
       op2.push_back(')');
       solve(op2,open,close-1,v);
   }
}

int main()
{
    int n=3;
    string op="";
    vector<string> v;
    int open=n;
    int close=n;
    solve(op,open,close,v);
    for(auto x:v)
    cout<<x<<" ";
    
    return 0;
}
