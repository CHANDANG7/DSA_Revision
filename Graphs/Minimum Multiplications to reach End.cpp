// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        q.push({start,0});
        if(start==end) return 0;
        int mod=100000;
        while(!q.empty())
        {
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(auto it:arr)
            {
                int num=(node*it)%mod;
                if(dist[num]>steps+1)
                {
                    dist[num]=steps+1;
                    if(num==end) return steps+1;
                    q.push({num,steps+1});
                    
                }
            }
        }
        return -1;
        
    }
};
