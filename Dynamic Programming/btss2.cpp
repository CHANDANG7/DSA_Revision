//Recursion
class Solution {
    int solve(int ind,bool buy,vector<int>& prices)
    {
        if(ind==prices.size())
         return 0;
        
        if(buy)
        {
            int buyed=-prices[ind]+solve(ind+1,0,prices);
            int notbuyed=solve(ind+1,1,prices);
            return max(buyed,notbuyed);
        }
        else
        {
            int selled=prices[ind]+solve(ind+1,1,prices);
            int notselled=solve(ind+1,0,prices);
            return max(selled,notselled);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return solve(0,1,prices);
    }
};

//Memoization
class Solution {
    int solve(int ind,bool buy,vector<int>& prices,vector<vector<int>>&dp)
    {
        if(ind==prices.size())
         return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            int buyed=-prices[ind]+solve(ind+1,0,prices,dp);
            int notbuyed=solve(ind+1,1,prices,dp);
            return dp[ind][buy]=max(buyed,notbuyed);
        }
        else
        {
            int selled=prices[ind]+solve(ind+1,1,prices,dp);
            int notselled=solve(ind+1,0,prices,dp);
            return dp[ind][buy]=max(selled,notselled);
        }
        return dp[ind][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][1]=dp[n][0]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                 if(j==1)
                {
                    int buyed=-prices[i]+dp[i+1][0];
                    int notbuyed=dp[i+1][1];
                    dp[i][j]=max(buyed,notbuyed);
                }
                else
                {
                    int selled=prices[i]+dp[i+1][1];
                    int notselled=dp[i+1][0];
                    dp[i][j]=max(selled,notselled);
                }
            }
        }
        return dp[0][1];
    }
};

//Space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int aheadbuy,aheadnotbuy,currbuy,currnotbuy;
        aheadbuy=aheadnotbuy=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            currnotbuy=max(prices[ind]+aheadbuy,aheadnotbuy);
            currbuy=max(-prices[ind]+aheadnotbuy,aheadbuy);
            aheadbuy=currbuy;
            aheadnotbuy=currnotbuy;
        }
        return aheadbuy;
    }
};