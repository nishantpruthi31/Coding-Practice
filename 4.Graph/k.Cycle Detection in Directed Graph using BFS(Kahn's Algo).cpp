#include<bits/stdc++.h>
using namespace std;

/* detecting a cycle through BFS (reverse topo sort-Kahn's Algo) */
    bool isCyclic(vector<int> graph[],int v)
    {
        queue<int> q;
        vector<int> indegree(v,0);
        
        for(int i=0;i<v;i++)
        {
           for(auto it:graph[i])
           indegree[it]++;
        }
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int count=0;            // to keep count wewather toposort elements are equal to no. of nodes
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:graph[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(count==v)
        return false;  // i.e we found topoSort
        else 
        return true;
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
