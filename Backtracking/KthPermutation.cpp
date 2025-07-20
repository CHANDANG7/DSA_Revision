// Backtracking: Kth Permutation Sequence
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int k, vector<int>& path, vector<bool>& used, vector<int>& result) {
    if (path.size() == nums.size()) {
        k--;
        if (k == 0) result = path;
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, k, path, used, result);
        if (!result.empty()) return;
        path.pop_back();
        used[i] = false;
    }
}
