// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(V);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
      vector<int>dist(V,INT_MAX);
      dist[src]=0;
      pq.push({0,src});
      while(!pq.empty())
      {
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int adjdis=it.second;
            if(adjdis+dis<dist[adjnode])
            {
                dist[adjnode]=adjdis+dis;
                pq.push({dist[adjnode],adjnode});
            }
        }
      }
      return dist;
        
    }
};