// Greedy: Shortest Job First - Avg Waiting Time
class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long wt=0,totaltime=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size();i++)
        {
            wt+=totaltime;
            totaltime+=bt[i];
        }
        return (wt/bt.size());
    }
};
