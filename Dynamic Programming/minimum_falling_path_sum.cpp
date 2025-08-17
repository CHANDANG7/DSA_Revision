// Recursion
class Solution
{
    int solve(int i, int j, vector<vector<int>> &matrix, int m, int n)
    {
        if (j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        int up = matrix[i][j] + solve(i - 1, j, matrix, m, n);
        int rd = matrix[i][j] + solve(i - 1, j + 1, matrix, m, n);
        int ld = matrix[i][j] + solve(i - 1, j - 1, matrix, m, n);
        return min(up, min(rd, ld));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, solve(m - 1, i, matrix, m, n));
        }
        return mini;
    }
};

// Memoization
class Solution
{
    int solve(int i, int j, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + solve(i - 1, j, matrix, m, n, dp);
        int rd = matrix[i][j] + solve(i - 1, j + 1, matrix, m, n, dp);
        int ld = matrix[i][j] + solve(i - 1, j - 1, matrix, m, n, dp);
        return dp[i][j] = min(up, min(rd, ld));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, solve(m - 1, i, matrix, m, n, dp));
        }
        return mini;
    }
};

// Tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int down = matrix[i][j] + dp[i - 1][j];
                int ld = 1e9, rd = 1e9;
                if (j > 0)
                    ld = matrix[i][j] + dp[i - 1][j - 1];
                if (j < n - 1)
                    rd = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(down, min(ld, rd));
            }
        }
        int mini = dp[m - 1][0];
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, dp[m - 1][i]);
        }
        return mini;
    }
};

// Space optimization
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> dp(n, 0);
            for (int j = 0; j < n; j++)
            {

                int down = matrix[i][j] + prev[j];
                int ld = 1e9, rd = 1e9;
                if (j > 0)
                    ld = matrix[i][j] + prev[j - 1];
                if (j < n - 1)
                    rd = matrix[i][j] + prev[j + 1];
                dp[j] = min(down, min(ld, rd));
            }
            prev = dp;
        }
        int mini = prev[0];
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};