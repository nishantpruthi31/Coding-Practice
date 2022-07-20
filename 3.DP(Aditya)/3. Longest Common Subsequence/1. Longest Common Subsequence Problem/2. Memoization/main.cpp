

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int m,int n,vector<vector<int>> dp)
{
    if(m==0 || n==0)            // m is size of string x and n is of y
    {
        return dp[m][n]=0;
    }
    
    if(x[m-1]==y[n-1])
    return dp[m][n]= 1+lcs(x,y,m-1,n-1,dp);
    
    if(dp[m][n]!=-1)
    return dp[m][n];
    
    return dp[m][n]=max(lcs(x,y,m,n-1,dp),lcs(x,y,m-1,n,dp));
}

int main()
{
   string x;
   string y;
   
   cout<<"Enter strings"<<endl;
   cin>>x>>y;
   
   int m=x.size();
   int n=y.size();
   
   vector<vector<int>> dp(m+1,vector<int> (n+1,-1));          // dp array and initializing it with 1
   
   cout<<"Length of longest common-subsequence: "<<lcs(x,y,m,n,dp)<<endl;
   
    return 0;
}
