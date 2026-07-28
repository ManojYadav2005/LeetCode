// class Solution {
// public:
//     int solve(int idx,vector<int>&nums,vector<int>&dp){
//     if(idx>=nums.size()) return 0;
    
//     if(dp[idx]!=-1) return dp[idx];

//     int steal=nums[idx]+solve(idx+2,nums,dp);
//     int skip=solve(idx+1,nums,dp);
//     dp[idx]=max(steal,skip);
//     return dp[idx];
//     }

//     int rob(vector<int>& nums) {
//     int n=nums.size();    
//     vector<int>dp(n+1,-1);
//     return solve(0,nums,dp);  


//     }
// };



class Solution {
public:
   
    int rob(vector<int>& nums) {
    int n=nums.size();    
    vector<int>dp(n+1,0);
    
    if(n==1) return nums[0];
    dp[0]=0;
    dp[1]=nums[0];
    
    for(int idx=2;idx<=n;idx++){

    int steal=nums[idx-1]+dp[idx-2];
    int skip=dp[idx-1];

    dp[idx]=max(steal,skip);}
    
    return dp[n];

    }
};