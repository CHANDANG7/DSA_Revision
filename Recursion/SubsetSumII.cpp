// Recursion: Subset Sum II (count subsets)
#include <vector>
using namespace std;

int countSubsets(vector<int>& nums, int sum, int index) {
    if (sum == 0) return 1;
    if (index == nums.size() || sum < 0) return 0;

    int include = countSubsets(nums, sum - nums[index], index + 1);
    int exclude = countSubsets(nums, sum, index + 1);
    return include + exclude;
}
