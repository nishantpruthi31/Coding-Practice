
                  // Print count of subsequence of an array whose sum is k.
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int printF(int idx,int sum,int arr[],int n,int k)
{
    if(idx==n)
    {
        if(sum==k)
        {
            return 1;
        }
       else
       {
           return 0;
       }
    }
    
    // taking that index element
    
    sum+=arr[idx];
    int l=printF(idx+1,sum,arr,n,k);
    sum-=arr[idx];
    
    // not taking that element
    int r=printF(idx+1,sum,arr,n,k);
    
    return l+r;
}
int main()
{
    int arr[]={1,2,1};
    int n=3;
    int k=2;
    vector<int> res;
    
    int ans=printF(0,0,arr,n,k);
    cout<<endl<<ans;


    return 0;
}
