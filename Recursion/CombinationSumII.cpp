// Recursion: Combination Sum II (no duplicate combinations)
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum2Helper(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;

        curr.push_back(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], i + 1, curr, result);
        curr.pop_back();
    }
}
