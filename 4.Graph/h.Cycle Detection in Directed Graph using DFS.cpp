#include<bits/stdc++.h>
using namespace std;


bool check(int node,vector<int> graph[],vector<int> &vis,vector<int> &dfsVis)
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(check(it,graph,vis,dfsVis)) return true;
            }
            else if(dfsVis[it]==1)
            return true;
        }
        dfsVis[node]=0;
        return false;
    }
    
    bool isCyclic(vector<int> graph[],int V) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        for(int i=0;i<V;i++)
        {
        if(!vis[i])
        {
            if(check(i,graph,vis,dfsVis)) return true;
        }
        }
        return false;
    }

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
}


int main()
{
    int V=4;          // nodes are 0,1,2,3
    vector<int> graph[V];
    
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,3);
    
    
    if(isCyclic(graph,V))
    cout<<"Cycle"<<endl;
    else
    cout<<"Not a Cycle"<<endl;
    
    return 0;
}
