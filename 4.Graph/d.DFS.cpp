#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int node,vector<int> adj[],vector<int> &dfs,vector<int> &vis)
{
    dfs.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        dfsUtil(it,adj,dfs,vis);
    }
}


vector<int> dfsOfGraph(vector<int> adj[],int nodes)
{
  vector<int> dfs;
  vector<int> vis(nodes+1,0);
  for(int i=1;i<=nodes;i++)
  {
      if(!vis[i])
      dfsUtil(i,adj,dfs,vis);
  }
  return dfs;
}


void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int V = 7;
	// creating adjacency list of nodes as 1bases indexing i.e. 1 to n
	vector<int> adj[V+1];
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 7);
	addEdge(adj, 3, 5);
	addEdge(adj, 4, 6);
	addEdge(adj, 5, 7);
	
	/* calling for bfs*/
	vector<int> dfs=dfsOfGraph(adj,7);
	for(auto x:dfs)
	cout<<x<<" ";
	

	return 0;
}
