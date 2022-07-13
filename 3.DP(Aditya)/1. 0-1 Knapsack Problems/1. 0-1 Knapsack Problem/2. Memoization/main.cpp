/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
int dp[100][1000];        // assuming that n constraints was 1<=n<=100 
                                       // wt constraints was 1<=W<=1000
using namespace std;
int knapSack(int W,int wt[],int val[],int n)
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
    
}

int main()
{
    int val[]={60,100,120};
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    memset(dp, -1, sizeof(dp));
    cout << knapSack(W, wt, val, n);

    return 0;
}
