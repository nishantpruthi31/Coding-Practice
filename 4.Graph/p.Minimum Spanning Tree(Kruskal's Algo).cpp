

#include <bits/stdc++.h>

using namespace std;


struct node{
    int u,v,wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};
bool comp(node a,node b)
{
    return (a.wt<b.wt);
}

int findParent(int u,vector<int> &parent)
{
    if(u==parent[u])
    return u;
    
    return findParent(parent[u],parent);  
}



void unionn(int u, int v,vector<int> &parent,vector<int> &rank)
{
    u=findParent(u,parent);
    v=findParent(v,parent);
    
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else         // if arrs are equal
    {
        parent[v]=u;         // attaching it with union u
        rank[u]++;
    }
}


int main()
{
  int m;        // no of input by user i.e. no. of edges
  int N;      // no. of nodes 
  cout<<"enter  no. of nodes:";
  cin>>N;
  cout<<"enter no. of operations:";
  cin>>m;
  
  vector<node> edges;
  for(int i=0;i<m;i++)
  {
      int u,v,wt;
      cin>>u>>v>>wt;
      edges.push_back(node(u,v,wt));
  }
  sort(edges.begin(),edges.end(),comp);
  
  vector<int> parent(N);
  for(int i=0;i<N;i++)
  parent[i]=i;
  
  vector<int> rank(N,0);
  
  int cost=0;         // to count how much weight is there
  vector< pair<int,int> > mst;
  
  for(auto it:edges)
  {
      if(findParent(it.v,parent) != findParent(it.u,parent))  // i.e. if Different component then connect them
      {
          cost+=it.wt;
          mst.push_back({it.u,it.v});
          unionn(it.u,it.v,parent,rank);
      }
  }
  
  cout<<cost<<endl;
  for(auto it:mst)
  {
      cout<<it.first<<"--"<<it.second<<endl;
  }
  
 
  return 0;

    
}
