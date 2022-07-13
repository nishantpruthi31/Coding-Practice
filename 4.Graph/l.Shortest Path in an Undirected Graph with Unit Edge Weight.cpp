
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

vector<int> findPath(int src,vector<int> adj[],int V)
{
    vector<int> dist(V,INT_MAX);
    queue<int> q;
    
    dist[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    return dist;
    
    
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int V = 9;            // nodes are 0-8
	vector<int> adj[V];
	addEdge(adj, 0,1);
	addEdge(adj, 0,3);
	addEdge(adj, 1,2);
	addEdge(adj, 1,3);
	addEdge(adj, 3,4);
	addEdge(adj, 4,5);
	addEdge(adj, 5,6);
	addEdge(adj, 2,6);
	addEdge(adj, 6,7);
	addEdge(adj, 6,8);
	addEdge(adj, 7,8);
	
	
	vector<int> dist=findPath(0,adj,V);
	for(int i=0;i<dist.size();i++)
	{
	    cout<<dist[i]<<" ";
	}
	
	return 0;
}


