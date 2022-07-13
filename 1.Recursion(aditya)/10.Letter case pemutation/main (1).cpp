

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve (string op,string ip,vector<string> &v)
{
    if(ip.size()==0)
    {
       v.push_back(op);
        return;
    }
   
   if(isalpha(ip[0]))       // if char digits
   {
    string op1=op;
    string op2=op;
    
    op1.push_back(toupper(ip[0]));     
    op2.push_back(tolower(ip[0]));
    ip.erase(ip.begin()+0);    
    
    solve(op1,ip,v);
    solve(op2,ip,v);
   }
   else
   {
    string op1=op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(op1,ip,v);
   }
}

int main()
{
    string ip="A2b1";
    string op="";
    vector<string> v;
    solve(op,ip,v);
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    return 0;
}
