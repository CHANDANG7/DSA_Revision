class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node])
            {
                int nnode=it.first;
                int pprice=it.second;
                if(pprice+dis<dist[nnode] && stops<=k)
                {
                    dist[nnode]=pprice+dis;
                    q.push({stops+1,{nnode,dist[nnode]}});
                }
            }
        }


        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};