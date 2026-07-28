class Solution {
public:
    int solve(vector<int>& nums, int idx, int end) {
        int prev2=0;
        int prev1=nums[idx];

        for (int i=idx+1;i<=end;i++) {
            int steal=nums[i]+prev2;
            int skip=prev1;

            int curr=max(steal,skip);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();

        if (n==1) return nums[0];

        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};