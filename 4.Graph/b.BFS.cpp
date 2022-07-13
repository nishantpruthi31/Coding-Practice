#include<bits/stdc++.h>
using namespace std;

void findBfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &storeBfs)
  {
      queue<int> q;
      vis[node]=1;
      q.push(node);
      
      while(!q.empty())
      {
          int temp=q.front();
          q.pop();
          storeBfs.push_back(temp);
          for(auto it:adj[temp])
          {
              if(!vis[it])
              {
                  vis[it]=1;
                  q.push(it);
                  
              }
          }
      }
  }
vector<int> bfsOfGraph(vector<int> adj[],int v)
{
    vector<int> storeBfs;
    vector<int> vis(v+1,0);
    
  
        for(int i=1;i<=v;i++)
        {
            if(!vis[i])
            findBfs(i,adj,vis,storeBfs);
        }
        return storeBfs;
    
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
	vector<int> bfs=bfsOfGraph(adj,7);
	for(auto x:bfs)
	cout<<x<<" ";
	

	return 0;
}
