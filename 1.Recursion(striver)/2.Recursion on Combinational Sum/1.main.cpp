
                  // Print combination of an array elements whose sum is equal to target value.
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findCombinationSum(vector<vector<int>> &res,vector<int> &ds,int index,int arr[],int target,int n)
{
    if(index==n)
    {
        if(target==0)
        {
            res.push_back(ds);
        }
        return ;
    }
    // pickup element till it's capaable
    if(arr[index]<=target)
    {
        ds.push_back(arr[index]);
        findCombinationSum(res,ds,index,arr,target-arr[index],n);
        ds.pop_back();
    }
    
    findCombinationSum(res,ds,index+1,arr,target,n) ; // moving to next index as above cond fails 
}

vector<vector<int>> combinationSum(int arr[],int target,int n)
{
   vector<vector<int>> res;
   vector<int> ds;
findCombinationSum(res,ds,0,arr,target,n);
return res;
   
}
int main()
{
    int arr[]={2,3,6,7};
    
    int target=7;
    int n=4;
     
     vector<vector<int>> res;

    res= combinationSum(arr,target,n);
    
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
        
        cout<<endl;
    }

    return 0;
}
