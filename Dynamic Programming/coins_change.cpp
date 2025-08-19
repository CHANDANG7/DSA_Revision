//Recursion
class Solution {
    int solve(int n,int target,vector<int>& coins)
    {
        if(n==0)
        {
            if(target%coins[n]==0) return 1;
            else return 0;
        }
        int nontake=0+solve(n-1,target,coins);
        int take=0;
        if(target>=coins[n])
         take=solve(n,target-coins[n],coins);
        return nontake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(n-1,amount,coins);
    }
};

//Memoization
class Solution {
    int solve(int n,int target,vector<int>& coins, vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(target%coins[n]==0) return 1;
            else return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int nontake=0+solve(n-1,target,coins,dp);
        int take=0;
        if(target>=coins[n])
         take=solve(n,target-coins[n],coins,dp);
        return dp[n][target]=nontake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};

//Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

        // Base case: only first coin
        for(int i = 0; i <= amount; i++)
            dp[0][i] = (i % coins[0] == 0);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                long long nontake = dp[i-1][j];
                long long take = 0;
                if(j >= coins[i])
                    take = dp[i][j - coins[i]];
                dp[i][j] = take + nontake;
            }
        }

        return dp[n-1][amount];
    }
};

//space optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);

        // Base case: only first coin
        for(int i = 0; i <= amount; i++)
            prev[i] = (i % coins[0] == 0);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                long long nontake = prev[j];
                long long take = 0;
                if(j >= coins[i])
                    take = curr[j - coins[i]];
                curr[j] = take + nontake;
            }
            prev=curr;
        }

        return prev[amount];
    }
};
