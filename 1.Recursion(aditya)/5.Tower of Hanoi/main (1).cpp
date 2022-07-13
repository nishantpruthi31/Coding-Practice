#include <bits/stdc++.h>
using namespace std;
 
 void toh(int s,int d,int h,int n,int &moves)
 {
     if(n==1)
     {
     cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
     moves++;
     return ;
     }
     
     toh(s,h,d,n-1,moves);
     moves++;
     cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
     toh(h,d,s,n-1,moves);
     
 }
 
 
 
int main()
{
    int n;
    cin>>n;
    
    
    int source=1;
    int des=3;
    int helper=2;
    
    int moves=0;
    
    toh(source,des,helper,n,moves);
    cout<<moves;
    return 0;
}