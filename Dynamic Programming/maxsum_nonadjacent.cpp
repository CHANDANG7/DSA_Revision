//recursion
// User function template for C++
class Solution {
  public:
     int f(int ind,vector<int>&arr)
     {
         if(ind==0) return arr[ind];
         if(ind<0) return 0;
         int take=arr[ind]+f(ind-2,arr);
         int nontake=0+f(ind-1,arr);
         return max(take,nontake);
     }
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        return f(n-1,arr);
    }
};