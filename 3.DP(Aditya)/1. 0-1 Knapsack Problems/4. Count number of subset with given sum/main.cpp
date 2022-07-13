/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
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
    int arr[] = { 2,3,5,6,8,10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum=10;
    memset(dp,-1,sizeof(dp));
   cout<<subsetSumCount(arr,n,sum);
    return 0;
}