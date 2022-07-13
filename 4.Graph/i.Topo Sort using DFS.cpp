#include<bits/stdc++.h>
using namespace std;



void dfs(int node,vector<int> graph[],stack<int> &st,vector<int> &vis)
	{
	    vis[node]=1;
	    
	    for(auto it:graph[node])
	    {
	        if(!vis[it]) dfs(it,graph,st,vis);
	    }
	    st.push(node);
	}
	
	vector<int> topoSortDFS( vector<int> graph[],int V) 
	{
	    // code here
	    stack<int> st;
	    
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        dfs(i,graph,st,vis);
	    }
	    vector<int> topo;
	    while(!st.empty())
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}


void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
}


int main()
{
    int V=4;          // nodes are 0,1,2,3
    vector<int> graph[V];
    
    addEdge(graph,1,0);
    addEdge(graph,2,0);
    addEdge(graph,3,0);
    
    
    vector<int> topo=topoSortDFS(graph,V);
    for(auto x:topo)
    cout<<x<<" ";
    
    return 0;
}
