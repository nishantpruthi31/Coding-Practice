#include <iostream>
#include<bits/stdc++.h>
using namespace std;

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
    return 0;
    
    if(isPalindrome(x,i,j))
    return 0;
    
    for(int k=i;k<=j-1;k++)
    {
        int tempAns = solve(x,i,k)+solve(x,k+1,j)+1;           // this 1 is for the partition we did at k th index
        
        if(tempAns<result)
        {
            result=tempAns;
        }
        
    }
    return result;
}
int main()
{
    
    string x="nitina";                     // 1 partition so that nitin and a will be palindrome
    int n=x.size();
    
    int i=0;
    int j=n-1;
    cout<<solve(x,i,j);                // minimum cost to multiply 4 matrix
}