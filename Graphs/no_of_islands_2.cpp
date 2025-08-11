// User function Template for C++
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
class Solution {
    bool isValid(int nr,int nc,int n,int m)
    {
        return nr>=0 && nr<n && nc>=0 && nc<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
      vector<vector<int>>vis(n,vector<int>(m,0));
      disjoint ds(n*m);
      int count=0;
      vector<int>ans;
      for(auto it:operators)
      {
          int row=it[0];
          int col=it[1];
          if(vis[row][col]==1)
          {
              ans.push_back(count);
              continue;
          }
          vis[row][col]=1;
          count++;
          int dr[]={-1,0,1,0};
          int dc[]={0,1,0,-1};
          for(int i=0;i<4;i++)
          {
              int nr=row+dr[i];
              int nc=col+dc[i];
              if(isValid(nr,nc,n,m))
              {
                  if(vis[nr][nc]==1)
                  {
                      int node=row*m+col;
                      int adjnode=nr*m+nc;
                      if(ds.findparent(node)!=ds.findparent(adjnode))
                      {
                          count--;
                          ds.unionByrank(node,adjnode);
                      }
                  }
              }
          }
          ans.push_back(count);
      }
      return ans;
        
    }
};
