#include<bits/stdc++.h>
using namespace std;



vector<int> topoSortBFS(vector<int> graph[],int V)
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:graph[i])
	        indegree[it]++;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it:graph[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
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
    
    
    vector<int> topo=topoSortBFS(graph,V);
    for(auto x:topo)
    cout<<x<<" ";
    
    return 0;
}
