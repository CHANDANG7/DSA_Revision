A Bipartite Graph is one where you can split nodes into 2 sets such that no two adjacent nodes are in the same set.

You used BFS and 2-coloring (0 and 1) to check if adjacent nodes are always colored differently.

If any neighbor has same color as current node → not bipartite.

class Solution {
    bool check(int start,vector<vector<int>>& graph,int n,vector<int>&color)
    {
        color[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                 return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,graph,n,color)==false) return false;
            }
        }
        return true;
    }
};