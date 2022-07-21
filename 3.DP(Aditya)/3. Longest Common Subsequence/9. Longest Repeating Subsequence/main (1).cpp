#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
   string x;
   string y;
   
   cout<<"Enter strings"<<endl;
   cin>>x;
   
   y=x;
   
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
           
           else if(x[i-1]==y[j-1] && i!=j)                  // extra condition i!=j
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else
           {
               dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
           }
       }
   }
   
   cout<<"Length of longest repeating subsequence: "<<dp[m][n]<<endl;
   
    return 0;
}