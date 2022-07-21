

#include <iostream>

using namespace std;
int lcs(string x,string y,int m,int n)
{
    if(m==0 || n==0)            // m is size of string x and n is of y
    {
        return 0;
    }
    
    if(x[m-1]==y[n-1])
    return 1+lcs(x,y,m-1,n-1);
    
    return max(lcs(x,y,m,n-1),lcs(x,y,m-1,n));
}

int main()
{
   string x;
   string y;
   
   cout<<"Enter strings"<<endl;
   cin>>x>>y;
   
   cout<<"Length of longest common-subsequence: "<<lcs(x,y,x.size(),y.size())<<endl;
   

    return 0;
}
