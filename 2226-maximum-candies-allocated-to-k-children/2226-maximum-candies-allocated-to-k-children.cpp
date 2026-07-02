class Solution {
public:
    long long check(int mid, vector<int>& candies) {
        long long count=0;
        for(int i=0;i<candies.size();i++) {
        count+=candies[i]/mid;
        }
        return count;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int lo=1;
        int hi=0;
        
        for(int i=0;i<candies.size();i++) {
        hi=max(hi,candies[i]);
        }
        
        int ans=0;
        while (lo<=hi) {
        int mid=lo+(hi-lo) / 2;
        if(check(mid,candies) >= k) {
        ans=mid;
        lo=mid+1;
        }else{
        hi=mid-1;
        }
        }
        
        return ans;
    }
};