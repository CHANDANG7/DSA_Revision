// Greedy: Job Sequencing Problem
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return profit[a] > profit[b];
        });
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> used(maxDeadline + 1, -1);
        int count = 0, amount = 0;
        for(int i = 0; i < n; i++) {
            int jobIdx = idx[i];
            for(int j = deadline[jobIdx]; j >= 1; j--) {
                if(used[j] == -1) {
                    used[j] = jobIdx;
                    count++;
                    amount += profit[jobIdx];
                    break;
                }
            }
        }
        return {count, amount};
    }
};
