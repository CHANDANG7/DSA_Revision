class Solution {
    bool dfs(int node,vector<vector<int>> &edges,vector<int>&vis,vector<int>&pathvis)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:edges[node])
        {
            if(!vis[it])
            {
                if(dfs(it,edges,vis,pathvis)==true) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
};