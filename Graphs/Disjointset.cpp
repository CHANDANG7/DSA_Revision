#include<bits/stdc++.h>
using namespace std;
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
            size[up_u] += size[up_v]; 
        }
    }
};

int main()
{
  disjoint ds(7);
  ds.unionBysize(1,2);
  ds.unionBysize(2,3);
  ds.unionBysize(4,5);
  ds.unionBysize(6,7);
  ds.unionBysize(5,6);
  if(ds.findparent(3)==ds.findparent(7))
   cout<<"same"<<endl;
  else cout<<"Not same"<<endl;
  ds.unionBysize(3,7);
  if(ds.findparent(3)==ds.findparent(7))
   cout<<"same"<<endl;
  else cout<<"Not same"<<endl;
  return 0;
}