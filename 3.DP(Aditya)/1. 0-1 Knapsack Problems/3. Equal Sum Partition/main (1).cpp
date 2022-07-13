

#include <bits/stdc++.h>
using namespace std;
 

bool isSubsetSum(int arr[], int n, int sum, vector<vector<int> >& dp)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // return solved subproblem
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
 
    if (arr[n - 1] > sum)
        return dp[n][sum] =isSubsetSum(arr, n - 1, sum, dp);
 
 
    return dp[n][sum] = isSubsetSum(arr, n - 1, sum, dp) || isSubsetSum(arr, n - 1, sum - arr[n - 1], dp);
}
 

bool findPartiion(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
     vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
 
    return isSubsetSum(arr, n, sum / 2, dp);
}
 

int main()
{
    int arr[] = { 2,3,7,8,10,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
 
    int arr2[] = { 3, 1, 5, 9, 14 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    if (findPartiion(arr2, n2) == true)
        cout << endl
             << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << endl
             << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}
