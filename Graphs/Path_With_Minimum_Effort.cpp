class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        diff[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1) return diff[r][c];
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int neweffort=max(abs(heights[nr][nc]-heights[r][c]),dis);
                    if(neweffort<diff[nr][nc]){
                     diff[nr][nc]=neweffort;
                     pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }
         return 0;
    }
};