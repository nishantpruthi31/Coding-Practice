#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    
    int coin[] = { 1,2,3 };     // coin as wt
    int sum = 5;                      // sum as W
    int n = sizeof(coin) / sizeof(coin[0]);
    
    int dp[n+1][sum+1];
    //i==n , j==W  from recursion code
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)   // 1 st row
            {
                dp[i][j]=INT_MAX-1;
            }
            
            else if(j==0)      // 1 st columns
            {
                dp[i][j]=0;
            }
             else if(j==1 && i==1)     // 1 st row    (twist condition)
            {
                for(j=1;j<sum+1;j++)
                {
              if(j%coin[0]==0)
              {
                  dp[i][j]= j/coin[0];
              }
              else
              {
                  dp[i][j]=INT_MAX-1;
              }
                }
            }
            else if(coin[i-1]<=j)
            {
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);   
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n][sum];
   
    

    return 0;
}