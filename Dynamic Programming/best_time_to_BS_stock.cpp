class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mini = prices[0], profit = 0;
        for (int i = 1; i < n; i++)
        {
            int total = prices[i] - mini;
            mini = min(mini, prices[i]);
            profit = max(profit, total);
        }
        return profit;
    }
};