
                  // Print all subsequence of an array whose sum is k.
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printF(int idx,vector<int>&res,int sum,int arr[],int n,int k)
{
    if(idx==n)
    {
        if(sum==k)
        {
             for(auto x:res)
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    
    
    // taking that index element
    res.push_back(arr[idx]);
    sum+=arr[idx];
    printF(idx+1,res,sum,arr,n,k);
    res.pop_back();
    sum-=arr[idx];
    
    // not taking that element
    printF(idx+1,res,sum,arr,n,k);
}
int main()
{
    int arr[]={1,2,1};
    int n=3;
    int k=2;
    vector<int> res;
    
    printF(0,res,0,arr,n,k);


    return 0;
}
