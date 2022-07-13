

#include<bits/stdc++.h>

using namespace std;



void addEdge(int u,int v,vector<pair<int,int>> adj[],int weight)
{
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});
}

int main()
{
    int n=5;          // nodes are 0 to 4
    vector<pair<int,int>> adj[n];
    addEdge(0,1,adj,2);
    addEdge(0,3,adj,6);
    addEdge(1,2,adj,3);
    addEdge(1,3,adj,8);
    addEdge(1,4,adj,5);
    addEdge(2,4,adj,7);
    
    int parent[n];              
    int key[n];
    bool mstSet[n];
    
    for(int i=0;i<n;i++)
    {
        mstSet[i]=false;
        key[i]=INT_MAX;
    }
    // minValue is minimum wt of edge to reach that node
    
    priority_queue< pair<int,int> > pq;            // using min heap for pair of(minValue,it's index/node) ,queue will sort according to minValue
    
    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});        // 0 value 0 index i.e. first node
    
    for(int count=0;count<n-1;count++)                // so 5nodes there will be 4 edges
    {
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;
        
        for(auto it:adj[u])
        {
           int v=it.first;
           int weight=it.second;
           
          if(mstSet[v]==false && weight <key[v])  // agar weight uss node ke weight se km h key array m
          {
              parent[v]=u;
              pq.push({key[v],v});
              key[v]=weight;
          }
        }
    }
    cout<<0<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<":"<<i<<endl;
    }
    
    
    
   
    return 0;
}


