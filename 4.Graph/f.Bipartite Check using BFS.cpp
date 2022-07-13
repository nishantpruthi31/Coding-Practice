#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int node,vector<int> adj[],vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node]=1;
        
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            
            for(auto it:adj[temp] )
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[temp];
                    q.push(it);
                }
                else if(color[it]==color[temp])
                    return false;
            }
           
        }
         return true;
    }


bool isBipartite(vector<int> adj[],int V)
{
    vector<int> color(V,-1);
    
    for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteBFS(i,adj,color))
                    return false;
            }
        }
        return true;
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


int main()
{
    int V=4;          // nodes are 0,1,2,3
    vector<int> adj[V];
    
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    
    if(isBipartite(adj,V))
    cout<<"Bipartite"<<endl;
    else
    cout<<"Not a Bipartite"<<endl;
    
    return 0;
}
