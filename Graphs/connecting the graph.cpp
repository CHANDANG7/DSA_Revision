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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int extra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findparent(u)==ds.findparent(v))
            {
              extra++;
            }
            else
            {
                ds.unionByrank(u,v);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)count++;
        }
        int ans=count-1;
        if(extra>=ans) return ans;
        else return -1;
    }
};