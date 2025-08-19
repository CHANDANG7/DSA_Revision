//Recursion
class Solution {
    int solve(int m,int n,string s,string t)
    {
        if(n<0) return 1;
        if(m<0) return 0;
        if(s[m]==t[n])
        {
            return (solve(m-1,n-1,s,t)+solve(m-1,n,s,t));
        }
        return solve(m-1,n,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        return solve(m-1,n-1,s,t);
    }
};

//Memoization
class Solution {
    int solve(int m,int n,string s,string t,vector<vector<int>>&dp)
    {
        if(n<0) return 1;
        if(m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n])
        {
            return dp[m][n]=(solve(m-1,n-1,s,t,dp)+solve(m-1,n,s,t,dp));
        }
        return dp[m][n]=solve(m-1,n,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};

//Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int j = 1; j <= n; j++) dp[0][j] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                else
                    dp[i][j] = dp[i-1][j] % MOD;
            }
        }

        return dp[m][n] % MOD;
    }
};


//Space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<double>dp(n+1,0);
        dp[0]=1;

        for (int i = 1; i <= m; i++) {
            for (int j = n;j>0; j--) {
                if (s[i-1] == t[j-1])
                    dp[j] = dp[j-1]+dp[j];
            }
        }
        return (int)dp[n];
    }
};
