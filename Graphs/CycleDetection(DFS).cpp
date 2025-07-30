class Solution {
    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,adj,vis)==true) return true;
            }
            else if(it!=parent)
            {
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V);
        for(int i=0;i<V;i++)
        { if(!vis[i])
            if(dfs(i,-1,adj,vis)==true) return true;
        }
        return false;
    }
};