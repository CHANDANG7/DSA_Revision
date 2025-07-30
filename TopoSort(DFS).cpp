class Solution {
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);  // ✅ corrected adjacency list

        // Build adjacency list
        for(auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // directed edge from u to v
        }

        stack<int> st;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
