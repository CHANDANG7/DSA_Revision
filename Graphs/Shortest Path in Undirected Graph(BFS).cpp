//Find the shortest distance btw src to all nodes where each edge is weited of unit weight
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[node]+1<dist[it])
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=INT_MAX)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
        
    }
};