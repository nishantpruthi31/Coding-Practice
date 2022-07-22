#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];            // acc to constraints i,j
int result=INT_MAX;
int solve(int arr[],int i,int j)
{
    if(i>=j)
    return dp[i][j]=0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    for(int k=i;k<=j-1;k++)
    {
        int tempAns = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        
        if(tempAns<result)
        {
            result=tempAns;
        }
        
    }
    return dp[i][j]=result;
}
int main()
{
    
    int arr[]={40,20,30,10,30};                      // 5 elements hence 4 matrix
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int i=1;
    int j=n-1;
    
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,i,j);                // minimum cost to multiply 4 matrix
}
