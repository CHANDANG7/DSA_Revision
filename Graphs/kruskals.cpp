class Solution {
    class disjoint{
  vector<int>rank,parent,size;
  public:
   disjoint(int n)
   {
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {
      parent[i]=i;
    }
   }
   int findparent(int node)
   {
    if(node==parent[node])
     return node;
    return parent[node]=findparent(parent[node]);
   }

   void unionByrank(int u,int v)
   {
    int up_u=findparent(u);
    int up_v=findparent(v);
    if(up_v==up_u) return;
    if(rank[up_u]<rank[up_v])
    {
      parent[up_u]=up_v;
    }
    else if(rank[up_v]<rank[up_u])
    {
      parent[up_v]=up_u;
    }
    else{
      parent[up_v]=up_u;
      rank[up_u]++;
    }

   }
   void unionBysize(int u,int v)
   {
    int up_u=findparent(u);
    int up_v=findparent(v);
    if(up_v==up_u) return;
    if(size[up_u]<size[up_v])
    {
      parent[up_u]=up_v;
      size[up_v]+=size[up_u];
    }
    else
    {
      parent[up_v]=up_u;
      size[up_u]+=size[up_v];
    }
  }
};

  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](const auto edge1,const auto edge2){
            return edge1[2]<edge2[2];
        });
        int mst=0;
        disjoint ds(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(ds.findparent(u)!=ds.findparent(v))
            {
                mst+=wt;
                ds.unionBysize(u,v);
            }
        }
        return mst;
    }
};