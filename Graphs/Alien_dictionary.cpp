// This problem involves finding the correct order of characters in an alien language using Topological Sort (Kahn's algorithm).



class Solution {
    vector<int> toposort(vector<vector<int>>& adj, int V) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (ans.size() < V) return {};
        return ans;
    }

public:
    string findOrder(vector<string> &words) {
        set<char> uniqueChars;
        for (auto &word : words) {
            for (auto &ch : word) uniqueChars.insert(ch);
        }
        unordered_map<char,int> charToIndex;
        unordered_map<int,char> indexToChar;
        int idx = 0;
        for (auto ch : uniqueChars) {
            charToIndex[ch] = idx;
            indexToChar[idx] = ch;
            idx++;
        }
        int V = idx;
        vector<vector<int>> adj(V);

        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool foundDiff = false;
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[charToIndex[s1[ptr]]].push_back(charToIndex[s2[ptr]]);
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }

        vector<int> topo = toposort(adj, V);
        if (topo.empty()) return "";

        string ans = "";
        for (auto it : topo) {
            ans += indexToChar[it];
        }
        return ans;
    }
};