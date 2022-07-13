

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;
vector<string> v;


void solve (string op,string ip)
{
    if(ip.size()==0)
    {
        if(s.find(op)==s.end())
        {
            v.push_back(op);
            s.insert(op);
        }
        return;
    }
    /* copying samw output first */
    string op1=op;
    string op2=op;
    
    op2.push_back(ip[0]);     // jisme lena push_back
    ip.erase(ip.begin()+0);    // small input
    
    solve(op1,ip);
    solve(op2,ip);
}

int main()
{
    string ip="aabab";
    string op="";
    
     // for empty string
    solve(op,ip);
    
    cout<<v.size()<<endl;         // 1 empty string also
    for(auto x:v)
    {
        cout<<x<<" ";
    }

    return 0;
}
