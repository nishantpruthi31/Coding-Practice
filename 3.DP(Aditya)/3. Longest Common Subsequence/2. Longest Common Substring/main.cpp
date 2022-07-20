

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


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

   int res=INT_MIN;
   for(int i=0;i<m+1;i++)
   {
       for(int j=0;j<n+1;j++)
       {
           if(i==0 || j==0)         // same initialize
           dp[i][j]=0;
           
           else if(x[i-1]==y[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
               res=max(res,dp[i][j]);           // res will sotre maximum till now
              
           }
           else
           {
               dp[i][j]= 0;           // max(dp[i][j-1],dp[i-1][j]); this was for lcs
           }
       }
   }
   
   cout<<"Length of longest common-substring: "<<res<<endl;         // res will print the required ans
   
    return 0;
}
