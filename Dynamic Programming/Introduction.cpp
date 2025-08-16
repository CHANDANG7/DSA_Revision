#include <bits/stdc++.h>
using namespace std;
int f(int n, vector<int> &dp)
{
    // memoization
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n-1,dp)+ f(n-2,dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp) << endl;

    
    //Tabulation
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];

    //Space Optimization
    int prev=1,prev2=0;
    for(int i=2;i<=n;i++)
    {
        int curri=prev2+prev;
        prev2=prev;
        prev=curri;
    }
    cout<<prev;
    return 0;
}