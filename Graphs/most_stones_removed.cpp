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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int>stonemap;
        for(auto it:stones)
        {
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBysize(noderow,nodecol);
            stonemap[noderow]=1;
            stonemap[nodecol]=1;
        }
        int count=0;
        for(auto it:stonemap)
        {
            if(ds.findparent(it.first)==it.first)
             count++;
        }
        return n-count;
    }
};