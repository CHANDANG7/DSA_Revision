// Recursion: Combination Sum I
#include <vector>
using namespace std;

void combinationSumHelper(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (index == candidates.size() || target < 0) return;

    // Include candidates[index]
    curr.push_back(candidates[index]);
    combinationSumHelper(candidates, target - candidates[index], index, curr, result);

    // Exclude candidates[index]
    curr.pop_back();
    combinationSumHelper(candidates, target, index + 1, curr, result);
}
