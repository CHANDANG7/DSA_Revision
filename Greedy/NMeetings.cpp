// Greedy: N Meetings in One Room
class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
      int n=start.size();
      vector<int>idx(n,-1);
      for(int i=0;i<n;i++) idx[i]=i;
      sort(idx.begin(),idx.end(),[&](int a,int b){
          return end[a]<end[b];
      });
      int count=1,freetime=end[idx[0]];
      for(int i=1;i<n;i++)
      {
          if(start[idx[i]]>freetime)
          {
              count++;
              freetime=end[idx[i]];
          }
      }
      return count;
    }
};
