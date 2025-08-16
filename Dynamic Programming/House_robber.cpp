class Solution
{
    int maxsum(vector<int> &temp)
    {
        int n = temp.size();
        int prev1 = temp[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = temp[i] + prev2;
            int nontake = 0 + prev1;
            int curr = max(take, nontake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(maxsum(temp1), maxsum(temp2));
    }
};