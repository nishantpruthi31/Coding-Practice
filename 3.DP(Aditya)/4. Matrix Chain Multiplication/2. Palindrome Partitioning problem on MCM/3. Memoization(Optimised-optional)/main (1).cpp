#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int result=INT_MAX;
bool isPalindrome(string x,int i,int j)
{
    bool ans=true;
    while(i<=j)
    {
        if(x[i++]!=x[j--])
        {
            ans=false;
            break;
        }
    }
    return ans;
}

int solve(string x,int i,int j)
{
    if(i>=j)
    return dp[i][j]=0;
    
    if(isPalindrome(x,i,j))
    return dp[i][j]=0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    for(int k=i;k<=j-1;k++)
    {
        // more optimized version checking for sub-problems already solved or not 
        int left;
        if(dp[i][k]!=-1)   // left sub-problems
        {
           left=dp[i][k]; 
        }
        else
        {
            left=solve(x,i,k);
            dp[i][k]=left;             // storing after recursion
        }
        
        int right;
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        {
            right=solve(x,k+1,j);
            dp[k+1][j]=right;
        }
        
        int tempAns=left+right+1;
        
        //int tempAns = solve(x,i,k)+solve(x,k+1,j)+1;           // this 1 is for the partition we did at k th index
        
        if(tempAns<result)
        {
            result=tempAns;
        }
        
    }
    return dp[i][j]=result;
}
int main()
{
    
    string x="nitina";                     // 1 partition so that nitin and a will be palindrome
    int n=x.size();
    
    memset(dp,-1,sizeof(dp));
    
    int i=0;
    int j=n-1;
    cout<<solve(x,i,j);                // minimum cost to multiply 4 matrix
}