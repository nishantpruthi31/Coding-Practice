
                 
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool isPalindrome(string s,int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
        return false;
    }
    return true;
}

void func(int idx,string s,vector<string> &path,vector<vector<string>> &res)
{
    if(idx==s.size())
    {
        res.push_back(path);
        return;
    }
    
    for(int i=idx;i<s.size();i++)
    {
        if(isPalindrome(s,idx,i))
        {
            path.push_back(s.substr(idx,i-idx+1));
            func(i+1,s,path,res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partiotning(string s)
{
    vector<string> path;
    vector<vector<string>> res;
    func(0,s,path,res);
    return res;
}


int main()
{
    string s="aabb";
   
    vector<vector<string>> res=partiotning(s);
    
    for(auto x:res)
    {
    vector<string> p= x;
    for(int i=0;i<p.size();i++)
    {
    cout<<p[i]<<" ";
    }
    cout<<endl;
    }
    
    /*for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
        cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return 0;
}

