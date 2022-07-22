#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int result=INT_MAX;
int solve(int arr[],int i,int j)
{
    if(i>=j)
    return 0;
    
    for(int k=i;k<=j-1;k++)
    {
        int tempAns = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        
        if(tempAns<result)
        {
            result=tempAns;
        }
        
    }
    return result;
}
int main()
{
    
    int arr[]={40,20,30,10,30};                      // 5 elements hence 4 matrix
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int i=1;
    int j=n-1;
    cout<<solve(arr,i,j);                // minimum cost to multiply 4 matrix
}
