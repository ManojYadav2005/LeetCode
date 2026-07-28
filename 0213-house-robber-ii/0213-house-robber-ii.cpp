class Solution {
public:
    int solve(vector<int>& nums,int idx,int end) {
        int n = nums.size();

        vector<int> dp(n,0);

        dp[idx]=nums[idx];

        for (int i=idx+1;i<=end;i++) {
            int steal=nums[i];
            if(i-2>=idx)
            steal=steal+dp[i-2];

            int skip=dp[i-1];

            dp[i]=max(steal,skip);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();

        if (n==1)
        return nums[0];

        int case1=solve(nums,0,n-2); // Exclude last house
        int case2=solve(nums,1,n-1); // Exclude first house

        return max(case1,case2);
    }
};