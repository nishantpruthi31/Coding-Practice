
                  // Print all subsets of an array
                  // Note: avoic duplicates combinations
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printF(int idx,vector<int>&res,set<vector<int>> &s,int arr[],int n)
{
    if(idx==n)
    {
        sort(res.begin(),res.end());
        s.insert(res);
        return;
    }
    
    
    // taking that index element
    res.push_back(arr[idx]);
    printF(idx+1,res,s,arr,n);
    res.pop_back();
   
    
    // not taking that element
    printF(idx+1,res,s,arr,n);
}
int main()
{
    int arr[]={1,2,2};
    int n=3;
    
    set<vector<int>> s;
    vector<int> res;
    
    printF(0,res,s,arr,n);
    
    for(auto x:s)
    {
        vector<int> temp=x;
        if(temp.size()==0)
        cout<<"{}";
        for(auto i:temp)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

