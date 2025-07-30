use indegree

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        // Step 1: Build adjacency list
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        // Step 2: Compute indegree of each node
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Step 3: Push all nodes with 0 indegree into the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: BFS-based topological sort
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Optional: Detect cycle (if needed)
        // if(ans.size() != V) => Graph has a cycle

        return ans;
    }
};
