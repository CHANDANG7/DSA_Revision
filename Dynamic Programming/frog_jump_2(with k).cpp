// memoization
class Solution
{
    int f(int n, vector<int> &dp, vector<int> &heights, int k)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int minimum = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (n - i >= 0)
            {
                int jump = f(n - i, dp, heights, k) + abs(heights[n] - heights[n - i]);
                minimum = min(jump, minimum);
            }
        }
        return dp[n] = minimum;
    }

public:
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        return f(n - 1, dp, heights, k);
    }
};

// Tabulation
class Solution
{
public:
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
                }
            }
        }
        return dp[n - 1];
    }
};
