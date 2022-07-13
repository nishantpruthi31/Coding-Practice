#include <iostream>
#include<bits/stdc++.h>

using namespace std;
/*int knapSack(int W,int wt[],int val[],int n)
{
    if(n==0 || W==0)
    return 0;
    
    if(dp[n][W]!=-1)
    return dp[n][W];
    
    if(wt[n-1]<=W)
    {
        return dp[n][W]= max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    }
        return dp[n][W]=knapSack(W,wt,val,n-1);
    
} */

int main()
{
    int val[]={60,100,120};
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    int dp[n+1][W+1];
    //i==n , j==W  from recursion code
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W];
   
    

    return 0;
}