

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int &ans,int k,int index,vector<int> v)
{
    if(v.size()==1)
    {
        ans=v[0];
        return;
    }
    index=(index+k)%v.size(); // to calculate from current index which index to be deleted
    v.erase(v.begin()+index);     // to delete next element
    solve(ans,k,index,v);
}
int main()
{
    int n=5;
    int k=2;
    vector<int> v={1,2,3,4,5};
    k--;
   int ans;
   solve(ans,k,0,v);
   cout<<"Winner is: "<<ans;

    return 0;
}
