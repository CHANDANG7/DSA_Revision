//Recursion
class Solution {
    int solve(int i,int w,vector<int> &val,vector<int> &wt)
    {
        if(i==0)
        {
            if(wt[i]<=w) return wt[i];
            else return 0;
        }
        int nontake=0+solve(i-1,w);
        int take=-1e9;
        if(wt[i]<=w)
         take=val[i]+solve(i-1,w-wt[i]);
        return max(nontake,take);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int n=val.size();
       return solve(n-1,W,val,wt);
    }
};

//Memoization
class Solution {
    int solve(int i,int w,vector<int> &val,vector<int> &wt,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(wt[i]<=w) return val[i];
            else return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int nontake=0+solve(i-1,w,val,wt,dp);
        int take=-1e9;
        if(wt[i]<=w)
         take=val[i]+solve(i-1,w-wt[i],val,wt,dp);
        return dp[i][w]=max(nontake,take);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int n=val.size();
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(n-1,W,val,wt,dp);
    }
};

//Tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));

        // Base case: only first item available
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= W; j++) {
                int nontake = dp[i-1][j];
                int take = INT_MIN;
                if (wt[i] <= j)
                    take = val[i] + dp[i-1][j - wt[i]];
                dp[i][j] = max(take, nontake);
            }
        }

        return dp[n-1][W];
    }
};

//Space optimaztion
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W+1, 0);

        // Base case: only first item
        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        // Fill the DP array
        for (int i = 1; i < n; i++) {
            for (int j = W; j >= 0; j--) {
                int nontake = prev[j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];
                prev[j] = max(nontake, take);
            }
        }

        return prev[W];
    }
};
