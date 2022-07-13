

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void solve (string op,string ip)
{
    if(ip.size()==0)
    {
        cout<<op<<endl;
        return;
    }
    /* copying samw output first */
    string op1=op;
    string op2=op;
    
    op1.push_back('-');     // jisme lena push_back
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);    // small input
    
    solve(op1,ip);
    solve(op2,ip);
}

int main()
{
    string ip="ABC";
    string op="";
    
    op.push_back(ip[0]);     // becuase of first index we have 1 choice
    ip.erase(ip.begin()+0);
    
    solve(op,ip);
    
    
 
    
  
    return 0;
}
