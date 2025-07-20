// Greedy: Minimum Platforms Required
class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int count=0,maxcount=0;
        int i=0,j=0;
        while(i<arr.size())
        {
            if(arr[i]<=dep[j])
            {
                count++;
                i++;
                maxcount=max(maxcount,count);
            }
            else
            {
                count--;
                j++;
            }
        }
        return maxcount;
    }
};
