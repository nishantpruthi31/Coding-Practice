#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 1; v < V; ++v)
	{
		cout << v<<": ";
		for (auto x : adj[v])
		cout << x<<" ";
		printf("\n");
	}
}

// Driver code
int main()
{
	int V = 5;
	vector<int> adj[V+1];
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 5);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 5);
	addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	printGraph(adj, V+1);
	return 0;
}


