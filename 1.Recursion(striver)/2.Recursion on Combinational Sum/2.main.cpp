
                  // Print combination of an array elements whose sum is equal to target value,cond:
                  // one element can be picked once
                  // no duplications of combinations
                  // all combinations in sorted order
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findCombinationSum(set<vector<int>> &res,vector<int> &ds,int index,int arr[],int target,int n)
{
    if(index==n)
    {
        if(target==0)
        {
            res.insert(ds);                           // using set to avoid duplicacy
        }
        return ;
    }
    
    if(arr[index]<=target)
    {
        ds.push_back(arr[index]);
        findCombinationSum(res,ds,index+1,arr,target-arr[index],n);                        // idx+1 unlike other as 1 element 1 time
        ds.pop_back();
    }
    
    findCombinationSum(res,ds,index+1,arr,target,n) ; 
}

set<vector<int>> combinationSum(int arr[],int target,int n)
{
   set<vector<int>> res;
   vector<int> ds;
findCombinationSum(res,ds,0,arr,target,n);
return res;
   
}
int main()
{
    int arr[]={1,1,2,2,2};                 // array must be sorted to have sorted combination
    
    int target=4;
    int n=5;
     
     set<vector<int>> res;

    res= combinationSum(arr,target,n);
    
    for(auto i=res.begin();i!=res.end();i++)
    {
      vector<int> result=*i;
      for(auto x:result)
      cout<<x<<" ";
      
      cout<<endl;
    } 

    return 0;
}
