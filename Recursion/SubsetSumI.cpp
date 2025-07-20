// Recursion: Subset Sum I
#include <vector>
using namespace std;

bool subsetSum(vector<int>& nums, int sum, int index) {
    if (sum == 0) return true;
    if (index == nums.size() || sum < 0) return false;

    // Include nums[index]
    if (subsetSum(nums, sum - nums[index], index + 1)) return true;
    // Exclude nums[index]
    return subsetSum(nums, sum, index + 1);
}
