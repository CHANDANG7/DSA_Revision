// User function Template for C++

class Solution
{
    int solve(int i, int n, vector<int> &price)
    {
        if (i == 0)
        {
            return n * price[i];
        }
        int nontake = 0 + solve(i - 1, n, price);
        int take = 0;
        if (i + 1 <= n)
            take = price[i] + solve(i, n - (i + 1), price);
        return max(take, nontake);
    }

public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        return solve(n - 1, n, price);
    }
};

// Memoization
//  User function Template for C++

class Solution
{
    int solve(int i, int n, vector<int> &price, vector<vector<int>> dp)
    {
        if (i == 0)
        {
            return n * price[i];
        }
        if (dp[i][n] != -1)
            return dp[i][n];
        int nontake = 0 + solve(i - 1, n, price, dp);
        int take = 0;
        if (i + 1 <= n)
            take = price[i] + solve(i, n - (i + 1), price, dp);
        return dp[i][n] = max(take, nontake);
    }

public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, n, price, dp);
    }
};
// Tabulation

// User function Template for C++

// User function Template for C++

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[0][i] = i * price[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int nontake = 0 + dp[i - 1][j];
                int take = 0;
                if (i + 1 <= j)
                    take = price[i] + dp[i][j - (i + 1)];
                dp[i][j] = max(take, nontake);
            }
        }
        return dp[n - 1][n];
    }
};
// Space optimization
//  User function Template for C++

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> prev(n + 1, 0);
        for (int i = 0; i <= n; i++)
            prev[i] = i * price[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int nontake = 0 + prev[j];
                int take = 0;
                if (i + 1 <= j)
                    take = price[i] + prev[j - (i + 1)];
                prev[j] = max(take, nontake);
            }
        }
        return prev[n];
    }
};