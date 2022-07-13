

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string op,int zero,int one,int n,vector<string> &v)
{
    if(n==0)
    {
        v.push_back(op);
        return ;
    }
    
    // sirf 1 ki choice
        string op1=op;
        op1.push_back('1');
        solve(op1,zero,one+1,n-1,v);
    if(one>zero)
    {
        string op2=op;
        op2.push_back('0');
        solve(op2,zero+1,one,n-1,v);
    }
    
    
}
int main()
{
    int n=3;
    string op="";
    vector<string> v;
    solve(op,0,0,n,v);
    for(auto x:v)
    cout<<x<<" ";

    return 0;
}
