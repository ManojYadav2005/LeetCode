class Solution {
public:
    int solve(int idx,vector<int>&nums,int end,vector<int>&dp){
    if(idx>end) return 0;
    
    if(dp[idx]!=-1) return dp[idx];

    int steal=nums[idx]+solve(idx+2,nums,end,dp);
    int skip=solve(idx+1,nums,end,dp);
    
    dp[idx]=max(steal,skip);
    return dp[idx];
    }

    int rob(vector<int>& nums){
     int n=nums.size();
     if (n==1) return nums[0];   

     vector<int>dp1(n+1,-1);
     vector<int>dp2(n+1,-1);

    int zrotolastone=solve(0,nums,n-2,dp1); 
    int zronottak=solve(1,nums,n-1,dp2);

    return max(zrotolastone,zronottak);

    }
};