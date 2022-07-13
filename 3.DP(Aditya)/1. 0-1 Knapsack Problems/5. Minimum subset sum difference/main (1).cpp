#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool dp[100][1000];
void subsetSum(int arr[],int sum,int n,vector<int>& storeS1)
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
    // storing s1 from last row
    for(int i=n;i<n+1;i++)
    {
        for(int j=1;j<=sum/2;j++)        // to go half way and excluding 0
        {
            if(dp[i][j]==true)             // that sum possible by s1
            {
                storeS1.push_back(j);
            }
        }
    }

   
}

int main()
{
    int arr[]={1,2,7};      
                                  
    int n = sizeof(arr) / sizeof(arr[0]);
    
 
    
    // finding range i.e. sum 
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    vector<int> storeS1;        // to store value of s1 from last row
    subsetSum(arr,sum,n,storeS1);        // to generate table
    
    cout<<sum<<endl;
    cout<<dp[0][0]<<endl;
    /*for(auto x:storeS1)
    {
    cout<<x<<" "; 
    }
    cout<<endl;*/
  
  int result=INT_MAX;
    for(auto x:storeS1)
    {
        result= min(result, sum-(2*x));               // range - 2 *s1
    }
    cout<<result; 
    return 0;
}