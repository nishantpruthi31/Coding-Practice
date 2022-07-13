#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int node,vector<int> graph[],vector<int> &color)
    {
        
        if(color[node]==-1) 
        color[node]=1;
     
        
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
            if(!bipartiteDFS(it,graph,color))
                return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
            
    }

bool isBipartite(vector<int> graph[],int V)
{
    vector<int> color(V,-1);
    
    for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteDFS(i,graph,color))
                    return false;
            }
        }
        return true;
}

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}


int main()
{
    int V=4;          // nodes are 0,1,2,3
    vector<int> graph[V];
    
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    
    if(isBipartite(graph,V))
    cout<<"Bipartite"<<endl;
    else
    cout<<"Not a Bipartite"<<endl;
    
    return 0;
}
