
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void solve(string op,int opN,int temp2n,int n)

{
    if(opN==0)
    {
        string temp=op;
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            sum1+= op[i]-'0'+1;
        }
        int sum2=0;
        for(int i=n;i<temp2n;i++)
        {
           sum2+= op[i]-'0'+1; 
        }
        if(sum1==sum2)
        {
           res.push_back(op); 
        }
        return;
       
    }
    
    string op1=op;
    string op2=op;
    
    op1.push_back('0');
    op2.push_back('1');
    
    solve(op1,opN-1,temp2n,n);
     solve(op2,opN-1,temp2n,n);
    
    
}

using namespace std;

int main()
{
    int n=3;
    int opN=2*n;
    int temp2n=opN;
    string op="";
    solve(op,opN,temp2n,n);
    for(auto x:res)
    cout<<x<<endl;
    
    cout<<res.size();
    
    return 0;
}
