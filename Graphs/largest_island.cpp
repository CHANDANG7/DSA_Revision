class disjoint {
public:
    vector<int> rank, parent, size;
    disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;  // Initialize size = 1 for each node
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
        }
        else if (rank[up_v] < rank[up_u]) {
            parent[up_v] = up_u;
        }
        else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
    void unionBysize(int u, int v) {
        int up_u = findparent(u);
        int up_v = findparent(v);
        if (up_v == up_u) return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];  // Fix here
        }
    }
};

class Solution {
    bool isValid(int nr, int nc, int n) {
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n * n);
        
        // Step 1: Union adjacent lands
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0 };
                int dc[] = { 0, 1, 0, -1 };
                int node = row * n + col;
                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int adjnode = nr * n + nc;
                        ds.unionBysize(node, adjnode);
                    }
                }
            }
        }
        
        int mx = 0;
        // Step 2: For every zero, check union of adjacent island sizes
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0 };
                int dc[] = { 0, 1, 0, -1 };
                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        components.insert(ds.findparent(nr * n + nc));
                    }
                }
                int totalsize = 1; // count this flipped cell as well
                for (auto it : components) {
                    totalsize += ds.size[it];
                }
                mx = max(mx, totalsize);
            }
        }

        // Step 3: Edge case: entire grid is 1s, no zeros to flip
        for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findparent(i)]);
        }

        return mx;
    }
};
