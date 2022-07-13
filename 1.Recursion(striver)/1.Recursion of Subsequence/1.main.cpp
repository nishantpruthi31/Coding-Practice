
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void printF(int arr[],vector<int> &res,int n,int idx)
{
    if(idx==n)
    {
        for(auto x:res)
        {
        cout<<x<<" ";
        }
        
        if(res.size()==0)
        cout<<"{}";
        cout<<endl;
        return;
    }
    
    
    // taking that index element
    res.push_back(arr[idx]);
    printF(arr,res,n,idx+1);
    res.pop_back();
    
    // not taking that element
    printF(arr,res,n,idx+1);
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> res;
    cout<<"{"<<endl;
    printF(arr,res,n,0);
    cout<<"}";

    return 0;
}
