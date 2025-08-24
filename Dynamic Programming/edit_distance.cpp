// Recursion
class Solution
{
    int solve(int i, int j, string s1, string s2)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (s1[i] == s2[j])
            return 0 + solve(i - 1, j - 1, s1, s2);
        else
        {
            int a = 1 + solve(i, j - 1, s1, s2);
            int b = 1 + solve(i - 1, j, s1, s2);
            int c = 1 + solve(i - 1, j - 1, s1, s2);
            return min(a, min(b, c));
        }
        return 0;
    }

public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        return solve(m - 1, n - 1, word1, word2);
    }
};
// memoization
class Solution
{
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
        else
        {
            int a = 1 + solve(i, j - 1, s1, s2, dp);
            int b = 1 + solve(i - 1, j, s1, s2, dp);
            int c = 1 + solve(i - 1, j - 1, s1, s2, dp);
            return dp[i][j] = min(a, min(b, c));
        }
        return 0;
    }

public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, word1, word2, dp);
    }
};
// Tabulation
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min(
                                       dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[m][n];
    }
};

// Space optimization
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int j = 0; j <= n; j++)
            prev[j] = j;

        for (int i = 1; i <= m; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    curr[j] = 1 + min({prev[j],
                                       curr[j - 1],
                                       prev[j - 1]});
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
