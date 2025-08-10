class Solution {
    class disjoint {
    public:
        vector<int> rank, parent;
        disjoint(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findparent(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findparent(parent[node]);
        }

        void unionByrank(int u, int v) {
            int up_u = findparent(u);
            int up_v = findparent(v);
            if (up_v == up_u) return;
            if (rank[up_u] < rank[up_v]) {
                parent[up_u] = up_v;
            } else if (rank[up_v] < rank[up_u]) {
                parent[up_v] = up_u;
            } else {
                parent[up_v] = up_u;
                rank[up_u]++;
            }
        }
    };

public:
    int numProvinces(vector<vector<int>> adj, int V) {
        disjoint ds(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1) {
                    ds.unionByrank(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (ds.findparent(i) == i) {
                count++;
            }
        }
        return count;
    }
};
