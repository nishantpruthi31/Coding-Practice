
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void insert(vector<int> &arr, int temp)
{
    if(arr.size()==0 || temp>=arr[arr.size()-1])
    {
        arr.push_back(temp);
        return ;
    }
    
    int val=arr[arr.size()-1];
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(val);
}

void sort(vector<int> &arr)
{
    if(arr.size()==1)
    return ;
    
    int val=arr[arr.size()-1];
    arr.pop_back();
    sort(arr);
    insert(arr,val);
}

int main()
{
vector<int> arr={1,7,2,5,6};
sort(arr);

for(auto x: arr)
cout<<x<<" ";

    return 0;
}