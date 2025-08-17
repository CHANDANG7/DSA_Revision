// Memoization
class Solution
{
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = INT_MAX, left = INT_MAX;
        if (i > 0)
            up = grid[i][j] + solve(i - 1, j, grid, dp);
        if (j > 0)
            left = grid[i][j] + solve(i, j - 1, grid, dp);
        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

// Tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    int left = INT_MAX;
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space Optimization
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> dp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[j] = grid[i][j];
                else
                {
                    int up = INT_MAX;
                    if (i > 0)
                        up = grid[i][j] + prev[j];
                    int left = INT_MAX;
                    if (j > 0)
                        left = grid[i][j] + dp[j - 1];
                    dp[j] = min(up, left);
                }
            }
            prev = dp;
        }
        return prev[n - 1];
    }
};