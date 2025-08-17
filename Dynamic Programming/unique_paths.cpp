// Recursion
class Solution
{
    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        int up = solve(i - 1, j);
        int left = solve(i, j - 1);
        return up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);
    }
};

// Memoization
class Solution
{
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = solve(i - 1, j, dp);
        int left = solve(i, j - 1, dp);
        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

// Tabulation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space optimization
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> temp(n, 0); // previous row

        for (int i = 0; i < m; i++)
        {
            vector<int> dp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = 1;
                }
                else
                {
                    int up = (i > 0) ? temp[j] : 0;
                    int left = (j > 0) ? dp[j - 1] : 0;
                    dp[j] = up + left;
                }
            }
            temp = dp;
        }

        return temp[n - 1];
    }
};
