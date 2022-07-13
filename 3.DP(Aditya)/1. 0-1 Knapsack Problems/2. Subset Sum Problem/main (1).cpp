#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool dp[100][1000];
bool subsetSum(int arr[],int sum,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
               dp[i][j]=false;
               
            }
            if(j==0)
            {
                 dp[i][j]=true;
            }
            
            else if(arr[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
   
}

int main()
{
    int arr[]={2,3,7,8,10};      //wt=arr 
                                  // w=sum
    int sum = 11;
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
  //vector<vector<bool>> dp(n + 1, vector<bool>(sum+1));
    //bool dp[n+1][sum+1];
    //i==n , j==W  from recursion code
  
    cout<<subsetSum(arr,sum,n)<<endl;
    return 0;
}
