
                  // Print only 1 subsequence of an array whose sum is k.
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool printF(int idx,vector<int>&res,int sum,int arr[],int n,int k)
{
    if(idx==n)
    {
        if(sum==k)
        {
             for(auto x:res)
            cout<<x<<" ";
            return true;
        }
       else
       {
           return false;
       }
    }
    
    // taking that index element
    res.push_back(arr[idx]);
    sum+=arr[idx];
    if(printF(idx+1,res,sum,arr,n,k)==true)
    {
        return true;
    }
    res.pop_back();
    sum-=arr[idx];
    
    // not taking that element
    if(printF(idx+1,res,sum,arr,n,k)==true)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[]={1,2,1};
    int n=3;
    int k=2;
    vector<int> res;
    
    bool ans=printF(0,res,0,arr,n,k);
    cout<<endl<<ans;


    return 0;
}
