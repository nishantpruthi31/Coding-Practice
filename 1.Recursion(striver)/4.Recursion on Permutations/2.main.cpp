
                  // Print all permutations of given array without using extra space
#include <iostream>
#include<bits/stdc++.h>

using namespace std;



void permute(int index,vector<vector<int>> &res,vector<int> arr)
{
    if(index==arr.size())
    {
        res.push_back(arr);
        return;
    }
    
   for(int i=index;i<arr.size();i++)
   {
       swap(arr[index],arr[i]);
       permute(index+1,res,arr);
       swap(arr[index],arr[i]);
   }
   
}
int main()
{
    vector<int> arr={1,2,3};
 
    
    vector<vector<int>> res;
    
    permute(0,res,arr);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        cout<<res[i][j]<<" ";
        
        cout<<endl;
    }
    return 0;
}

