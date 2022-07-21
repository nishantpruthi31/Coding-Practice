

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   string x;
   string y;
   
   cout<<"Enter strings"<<endl;                         // x>y
   cin>>x;
   
   string temp=x;
   reverse(temp.begin(),temp.end());
   y=temp ; // y string will be reverse of x 
   
   // now lcs between these two will be length of longest palindomic sub-sequence
   
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
   
   // minimum number of deletion will be length of string x - lps
   
   cout<<"Minimum number of deletions to make the string palindrome: "<<m-dp[m][n]<<endl;            
   
  
    return 0;
}
