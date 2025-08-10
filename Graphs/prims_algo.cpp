class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int>vis(V,0);
        vector<vector<pair<int,int>>>adj(V);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(!vis[node])
            {
                sum+=wt;
                vis[node]=1;
            }
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(vis[adjnode]!=1)
                {
                    pq.push({adjwt,adjnode});
                }
            }
            
        }
        return sum;
        
    }
};