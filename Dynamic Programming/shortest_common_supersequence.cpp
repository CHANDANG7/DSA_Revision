class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
         int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                ans+=text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                 ans+=text1[i-1];
                 i--;
            }
            else
            {
                ans+=text2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            ans+=text1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=text2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};