// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const long long INF = 1e18;
        vector<long long> dist(V, INF);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        // Convert to int, mark unreachable as 1e8
        vector<int> ans(V);
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) ans[i] = 100000000; // <-- FIXED
            else ans[i] = (int)dist[i];
        }

        return ans;
    }
};
