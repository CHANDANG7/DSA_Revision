class Solution {
    string beginWordGlobal;
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;

    void dfs(string word, vector<string>& seq) {
        if (word == beginWordGlobal) {
            vector<string> temp = seq;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};  // endWord not in list

        queue<string> q;
        q.push(beginWord);
        beginWordGlobal = beginWord;
        mpp[beginWord] = 1;
        int wordLen = beginWord.size();
        st.erase(beginWord);  // prevent revisit

        // BFS to find shortest paths
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < wordLen; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // Start DFS backtracking from endWord to beginWord
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};
