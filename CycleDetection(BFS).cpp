class Solution {
    bool detect(int src, vector<int>& vis, vector<vector<int>>& adj) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != parent) {
                    return true; // Cycle found
                }
            }
        }
        return false;
    }
    
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, vis, adj)) return true;
            }
        }
        return false;
    }
};
