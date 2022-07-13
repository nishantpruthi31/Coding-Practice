
                  // Print all subsets sum in an array of size n,in increasing order
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printF(int idx,vector<int>&res,int sum,int arr[],int n)
{
    if(idx==n)
    {
        res.push_back(sum);
        return;
    }
    
    
    // taking that index element
    printF(idx+1,res,sum+arr[idx],arr,n);
   
    
    // not taking that element
    printF(idx+1,res,sum,arr,n);
}
int main()
{
    int arr[]={3,1,4};
    int n=3;
    vector<int> res;
    
    printF(0,res,0,arr,n);
    sort(res.begin(),res.end());           // so that sum be in inreasing order
    for(auto x:res)
    cout<<x<<" ";


    return 0;
}

