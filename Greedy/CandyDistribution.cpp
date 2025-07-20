// Greedy: Candy Distribution (LeetCode 135)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1,i=1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                sum+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1])
            {
                down++;
                sum+=down;
                i++;
            }
            down++;
            if(down>peak) sum+=down-peak;
        }
        return sum;
    }
};
