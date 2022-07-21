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
   
   cout<<"Length of Shortest common super-sequence: "<<(m+n)-dp[m][n]<<endl;            
   
   int i=m;
   int j=n;
   
   string ans;
   
   while(i>0 && j>0 )                // ek string 0 ni hoti
   {
       if(x[i-1]==y[j-1])              // dono strings ke last character equal
       {
           ans.push_back(x[i-1]);
           i--;
           j--;
       }
       else if(dp[i][j-1]>dp[i-1][j])                     // agar left wala bda h upar wale se toh left move
       {
           ans.push_back(y[j-1]);         // string include krlo
           j--;
       }
       else
       {
           ans.push_back(x[i-1]);             // y wali string include krlo
          i--;
       }
   }
   
   //cout<<ans<<endl;
   
   while(i!=0)          // agar a string rehgi ho
   {
      ans.push_back(x[i-1]);
      i--;
   }
   
   while(j!=0)          // agar b string rehgi ho
   {
       ans.push_back(y[j-1]);
       j--;
   }
   reverse(ans.begin(),ans.end());
   cout<<"Shortest common super-sequence is: "<<ans<<endl;
   
    return 0;
}