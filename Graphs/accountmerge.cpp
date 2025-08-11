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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjoint ds(n);
        unordered_map<string,int> accountmap;  // email -> index of account

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (accountmap.find(mail) == accountmap.end()) {
                    accountmap[mail] = i;
                } else {
                    ds.unionByrank(i, accountmap[mail]);
                }
            }
        }

        vector<vector<string>> merged_mail(n);  // must be vector<vector<string>>

        for (auto& it : accountmap) {
            string mail = it.first;
            int node = ds.findparent(it.second);
            merged_mail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged_mail[i].empty()) continue;

            sort(merged_mail[i].begin(), merged_mail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& mail : merged_mail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
