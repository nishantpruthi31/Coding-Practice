#include<bits/stdc++.h>


using namespace std;

void findTopoSort(int node,stack<int> &st,vector<int> &vis,vector<pair<int,int>> adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it.first])
        {
            findTopoSort(it.first,st,vis,adj);
        }
    }
    st.push(node);
}

vector<int> findPath(int src,vector<pair<int,int>> adj[],int V)
{
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        findTopoSort(i,st,vis,adj);
    }
    
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        
        if(dist[node]!=INT_MAX)  // i.e. we have reached till that node than only we can traverse it's adjacent node
        {
            for(auto it:adj[node])
            {
                if(dist[node]+it.second<dist[it.first])
                dist[it.first]=dist[node]+it.second;
            }
        }
    }
    
    return dist;
}
void addEdge(int u,int v,vector<pair<int,int>> adj[],int weight)
{
    adj[u].push_back({v,weight});
}

int main()
{
    int V=6;          // nodes are 0 to 5
    vector<pair<int,int>> adj[V];
    addEdge(0,1,adj,2);
    addEdge(0,4,adj,1);
    addEdge(1,2,adj,3);
    addEdge(4,2,adj,2);
    addEdge(4,5,adj,4);
    addEdge(2,3,adj,6);
    addEdge(5,3,adj,1);
    
    vector<int> dist=findPath(0,adj,V);
    for(int i=0;i<V;i++)
    {
        if(i!=INT_MAX)
        cout<<dist[i]<<" ";
        else
        cout<<"Can't reach ";
    } 
    
    return 0;
}
