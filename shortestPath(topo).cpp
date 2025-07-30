//same as dijkstra
class Solution {
    void toposort(int node, vector<int>& vis, vector<vector<pair<int,int>>>& adj, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                toposort(v, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                toposort(i, vis, adj, st);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(dist[node] != INT_MAX) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Optional: mark unreachable nodes as -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};