// Greedy: Fractional Knapsack (GFG)
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>>items;
        for(int i=0;i<val.size();i++)
        {
            items.push_back({val[i],wt[i]});
        }
        sort(items.begin(),items.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first/(double)a.second>b.first/(double)b.second;
        });
        double totalval=0;
        for(int i=0;i<items.size();i++)
        {
            if(items[i].second<=capacity)
            {
                totalval+=items[i].first;
                capacity-=items[i].second;
            }
            else
            {
                totalval+=((items[i].first/(double)items[i].second)*capacity);
                break;
            }
            
        }
        return totalval;
    }
};
