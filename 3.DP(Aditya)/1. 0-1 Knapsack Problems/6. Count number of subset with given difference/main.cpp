#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[100][1000];

int subsetSumCount(int arr[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return 1;                  // ek hi case 
    if (n == 0 && sum != 0)
        return 0;
 
    // return solved subproblem
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
 
    if (arr[n - 1] > sum)
        return dp[n][sum] = subsetSumCount(arr, n - 1, sum);
 
 
    return dp[n][sum] = (subsetSumCount(arr, n - 1, sum) + subsetSumCount(arr, n - 1, sum - arr[n - 1]));
}
int main()
{
    int arr[]={1,1,2,3};   
    int diff=1;
                                  
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp,-1,sizeof(dp));
    
    // finding arraySum i.e. sum 
    int arraySum=0;
   
    for(int i=0;i<n;i++)
    {
        arraySum+=arr[i];
    }
    
    int sum = (diff + arraySum) / 2;   
    cout<<sum<<endl;                       // subset with given sum 4
    int count = subsetSumCount(arr,n,sum); 

    cout<<count; 
    return 0;
}