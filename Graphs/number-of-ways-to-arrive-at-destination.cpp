class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Build adjacency list: node -> list of {neighbor, time}
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        const int MOD = 1e9 + 7;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        // Min-heap for Dijkstra: {distance, node}
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if (curDist > dist[node]) continue; // Skip outdated entry

            for (auto &[neighbor, time] : adj[node]) {
                long long newDist = curDist + time;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                } else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
