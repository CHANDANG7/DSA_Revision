// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,int>>s;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto it=*(s.begin());
            int node=it.second;
            int dis=it.first;
            s.erase(it);
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjdis=it.second;
                if(adjdis+dis<dist[adjnode])
                {
                    if(dist[adjnode]!=INT_MAX)
                    {
                        s.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+adjdis;
                    s.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        
    }
};