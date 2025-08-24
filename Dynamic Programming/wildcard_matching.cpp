// Recursion
class Solution
{
    bool solve(int i, int j, string &s, string &p)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (j < 0 && i >= 0)
            return false;

        if (s[i] == p[j] || p[j] == '?')
            return solve(i - 1, j - 1, s, p);

        if (p[j] == '*')
            return solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        return solve(m - 1, n - 1, s, p);
    }
};

// Memoization
class Solution
{
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        if (p[j] == '*')
            return dp[i][j] = (solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp));
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }
};

// Tabulation
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
            dp[i][0] = false;
        for (int j = 1; j <= n; j++)
        {
            bool flag = true;
            for (int k = 0; k < j; k++)
            {
                if (p[k] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '*')
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};

// Space Optimization
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), curr(n + 1, false);

        // Base case: empty string and empty pattern
        prev[0] = true;

        // Base case: empty string and pattern starting with *
        for (int j = 1; j <= n; j++)
            prev[j] = prev[j - 1] && (p[j - 1] == '*');

        for (int i = 1; i <= m; i++)
        {
            curr[0] = false; // non-empty string cannot match empty pattern
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};
