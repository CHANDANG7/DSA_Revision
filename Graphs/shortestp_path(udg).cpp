class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        set<pair<int,int>>st;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
         parent[i]=i;
        dist[1]=0;
        st.insert({0,1});
        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjdis=it.second;
                if(dis+adjdis<dist[adjnode])
                {
                    if(dist[adjnode]!=INT_MAX)
                    {
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+adjdis;
                    st.insert({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        vector<int>res;
        res.push_back(dist[n]);     
        vector<int>ans;
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        res.insert(res.end(),ans.begin(),ans.end());// returning list which contains first the distance to node n and followed by path
        return res;
        
    }
};