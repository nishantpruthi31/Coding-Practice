
#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,int parent,vector<int> adj[],vector<int> &vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(checkCycle(it,node,adj,vis)) return true;
        }
        else if(it!=parent)
        return true;
    }
    return false;
}
bool isCycle(vector<int> adj[],int V)
{
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            if(checkCycle(i,-1,adj,vis)) return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int V= 11;
	// creating adjacency list of nodes as 1bases indexing i.e. 1 to n
	vector<int> adj[V+1];
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 4);
	addEdge(adj, 3, 5);
	addEdge(adj, 5, 6);
	addEdge(adj, 6, 7);
	addEdge(adj, 7, 8);
	addEdge(adj, 8, 11);
	addEdge(adj, 8, 9);
	addEdge(adj, 9, 10);
	addEdge(adj, 10, 5);
	
	bool ans=isCycle(adj,V);
	if(ans)
	cout<<"Cycle";
	else
	cout<<"No Cycle";
	return 0;
}
