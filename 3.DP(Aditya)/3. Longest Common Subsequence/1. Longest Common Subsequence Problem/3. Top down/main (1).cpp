

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*int lcs(string x,string y,int m,int n,vector<vector<int>> dp)
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
} */

int main()
{
   string x;
   string y;
   
   cout<<"Enter strings"<<endl;
   cin>>x>>y;
   
   int m=x.size();
   int n=y.size();
   
   vector<vector<int>> dp(m+1,vector<int> (n+1));          // dp array 
   
   
   // m==i n==j
   
   for(int i=0;i<m+1;i++)
   {
       for(int j=0;j<n+1;j++)
       {
           if(i==0 || j==0)         // initilize 1st row and 1 st column with 0
           dp[i][j]=0;
           
           else if(x[i-1]==y[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else
           {
               dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
           }
       }
   }
   
   cout<<"Length of longest common-subsequence: "<<dp[m][n]<<endl;
   
    return 0;
}
