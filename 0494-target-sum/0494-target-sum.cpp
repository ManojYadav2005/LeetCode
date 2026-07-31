class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {

        if (idx == 0) {
        if (sum == 0 && nums[0] == 0) return 2;
        if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int notTake = solve(idx - 1, sum, nums, dp);

        int take = 0;
        if (nums[idx] <= sum)
            take = solve(idx - 1, sum - nums[idx], nums, dp);

        return dp[idx][sum] = (take + notTake) % mod;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        // Not possible
        if (totalSum < abs(target))
            return 0;

        if ((totalSum - target) % 2 != 0)
            return 0;

        int reqSum=(totalSum-target)/2;

        vector<vector<int>> dp(nums.size(),vector<int>(reqSum+1,-1));

        return solve(nums.size()-1,reqSum,nums,dp);
    }
};