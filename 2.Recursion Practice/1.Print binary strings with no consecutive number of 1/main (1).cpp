
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(string op,int n,char prev,vector<string> &res)
{
    if(n==0)
    {
        res.push_back(op);
        return;
    }
    
    string op1=op;
    op1.push_back('0');
    solve(op1,n-1,'0',res);
    
    if(prev=='0')          // 1 tbhi aa skta jb pichla zero ho
    {
       string op2=op;
       op2.push_back('1');
       solve(op2,n-1,'1',res);
    }
    
}
int main()
{
    int n=3;
    vector<string> res;
    char prev='0';
    string op="";
    
    solve(op,n,prev,res);
    
    for(auto x:res)
    cout<<x<<" ";

    return 0;
}
