
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> findPath(int src,vector<pair<int,int>> adj[],int V)
{
      vector<int> distTo(V+1,INT_MAX);
    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;   // pair(dist,node);
    priority_queue<pair<int,int>> pq; /* this is same as above i.e. min heap in dist key not on node value */
    
    distTo[src]=0;
    pq.push({0,src});
    
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        
        for(auto it:adj[prev])
        {
            int next=it.first;
            int nextDist=it.second;
            
            if(distTo[next]>distTo[prev]+nextDist)
            {
                distTo[next]=distTo[prev]+nextDist;
                pq.push({distTo[next],next});
            }
            
            
        }
    }
   return distTo;
}

void addEdge(int u,int v,vector<pair<int,int>> adj[],int weight)
{
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});
}

int main()
{
    int V=5;          // nodes are 1 to 5
    vector<pair<int,int>> adj[V+1];
    addEdge(1,2,adj,2);
    addEdge(1,4,adj,1);
    addEdge(2,5,adj,5);
    addEdge(2,3,adj,4);
    addEdge(3,4,adj,3);
    addEdge(3,5,adj,1);
    
    
    vector<int> dist=findPath(2,adj,V);
    for(int i=1;i<=V;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}


