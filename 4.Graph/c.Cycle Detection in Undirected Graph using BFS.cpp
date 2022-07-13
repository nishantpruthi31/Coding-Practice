#include<bits/stdc++.h>

using namespace std;

bool checkCycle(int node,vector<int> adj[],vector<int> &vis)
{
    queue<pair<int,int>> q;
    vis[node]=1;
    q.push({node,-1});
    
    while(!q.empty())
    {
        int tempNode=q.front().first;
        int par=q.front().second;
        
        for(auto it:adj[tempNode])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,tempNode});
            }
            else if(par!=it)
            return true;
        }
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
        if(checkCycle(i,adj,vis)) return true;
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