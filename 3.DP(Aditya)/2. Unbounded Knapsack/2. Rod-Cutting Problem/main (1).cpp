#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int N=8;      // rode of size 8         // N as W
    
    int length[]={1,2,3,4,5,6,7,8};            // length array as w array
    int n=sizeof(length)/sizeof(length[0]);     
    int price[] = { 1,5,8,9,10,17,19,20 };        // price array as value array

    int dp[n+1][N+1];
   
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<N+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(length[i-1]<=j)
            {
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][N];
   
    

    return 0;
}