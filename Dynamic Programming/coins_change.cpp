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
         take=coins[n]+solve(n,target-coins[n],coins);
        return nontake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(n-1,amount,coins);
    }
};

