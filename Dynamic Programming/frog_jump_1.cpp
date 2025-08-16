// Memoization
class Solution
{
    int f(int n, vector<int> &stones, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int left = f(n - 1, stones, dp) + abs(stones[n] - stones[n - 1]);
        int right = INT_MAX;
        if (n > 1)
            right = f(n - 2, stones, dp) + abs(stones[n] - stones[n - 2]);

        return dp[n] = min(left, right);
    }

public:
    int maxJump(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> dp(n, -1); // dp[0..n-1]
        return f(n - 1, stones, dp);
    }
};

// Tabulation
class Solution
{
public:
    int maxJump(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int fs = dp[i - 1] + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = dp[i - 2] + abs(stones[i] - stones[i - 2]);

            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }
};

// Space optimization
class Solution
{
public:
    int maxJump(vector<int> &stones)
    {
        int n = stones.size();
        int prev1 = 0, prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int fs = prev1 + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = prev2 + abs(stones[i] - stones[i - 2]);

            int curri = min(fs, ss);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
        ;
    }
};