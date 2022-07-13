
#include <iostream>
using namespace std;
void solve(string op,string ip)
{
    if(ip.size()==0)
    {
    cout<<op<<endl;
    return ;
    }
    string op1=op;
    string op2=op;
    
    op1.push_back(' ');
    op1.push_back(ip[0]);
    
    op2.push_back(ip[0]);
    
    ip.erase(ip.begin()+0);
    
    solve(op1,ip);
    solve(op2,ip);
}

using namespace std;

int main()
{
    string ip="123";
    string op="";
    
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(op,ip);
    
    
    return 0;
}
