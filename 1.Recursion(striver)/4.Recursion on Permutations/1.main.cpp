
                  // Print all permutations of given array 
                  // n!*n approach
#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void permute(vector<vector<int>> &res,vector<int>&ds,int freq[],int arr[],int n)
{
    if(ds.size()==n)
    {
        res.push_back(ds);
        return;
    }
    
   for(int i=0;i<n;i++)
   {
       if(freq[i]==0)
       {
           ds.push_back(arr[i]);
           freq[i]=1;
           permute(res,ds,freq,arr,n);
           freq[i]=0;
           ds.pop_back();
       }
   }
   
}
int main()
{
    int arr[]={1,2,3};
    int n=3;
    int freq[n]={0};
    vector<vector<int>> res;
    vector<int> ds;
    permute(res,ds,freq,arr,n);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

