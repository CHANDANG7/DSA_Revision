A node is safe if:

Starting from that node, you cannot reach a cycle, no matter which path you take.

We can solve this using DFS:

If a node is part of a cycle or leads to a cycle → not safe.

If it leads only to terminal nodes → safe.

class Solution {
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>&check,vector<vector<int>>& graph)
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,check,graph)==true)
                { check[it]=0;
                return true;
                }
            }
            else if(pathvis[it]==1)
            {
                check[it]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,-1);
        for(int i=0;i<n;i++)
        {
            dfs(i,vis,pathvis,check,graph);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
               ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};