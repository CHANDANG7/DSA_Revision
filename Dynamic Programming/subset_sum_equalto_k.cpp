// Recursion
class Solution
{
    bool solve(int i, int target, vector<int> &arr)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return (arr[0] == target);
        bool nontake = solve(i - 1, target, arr);
        bool take = false;
        if (target > arr[i])
            take = solve(i - 1, target - arr[i], arr);
        return (take || nontake);
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        return solve(n - 1, sum, arr);
    }
};

// Memoization
class Solution
{
    bool solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return (arr[0] == target);
        if (dp[i][target] != -1)
            return dp[i][target];
        bool nontake = solve(i - 1, target, arr, dp);
        bool take = false;
        if (target > arr[i])
            take = solve(i - 1, target - arr[i], arr, dp);
        return dp[i][target] = (take || nontake);
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
    }
};

// Tabulation
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int k = 1; k <= sum; k++)
            {
                bool nontake = dp[i - 1][k];
                bool take = false;
                if (arr[i] <= k)
                    take = dp[i - 1][k - arr[i]];
                dp[i][k] = (take || nontake);
            }
        }
        return dp[n - 1][sum];
    }
};

// Space optimization
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);
        prev[0] = 1;
        curr[0] = 1;
        prev[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int k = 1; k <= sum; k++)
            {
                bool nontake = prev[k];
                bool take = false;
                if (arr[i] <= k)
                    take = prev[k - arr[i]];
                curr[k] = (take || nontake);
            }
            prev = curr;
        }
        return prev[sum];
    }
};