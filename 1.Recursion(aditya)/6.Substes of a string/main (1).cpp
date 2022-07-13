

#include <iostream>

using namespace std;

void solve (string op,string ip)
{
    if(ip.size()==0)
    {
        cout<<op<<" ";
        if(op.size()==0)
        cout<<"$"<<" ";
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
    string ip="abc";
    string op="";
    
    solve(op,ip);

    return 0;
}
