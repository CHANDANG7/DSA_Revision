// Greedy: Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int r=0,maxi=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxi=max(maxi,i+nums[i]);
            if(i==r)
            {
                jumps++;
                r=maxi;
            }
        }
        return jumps;
    }
};
