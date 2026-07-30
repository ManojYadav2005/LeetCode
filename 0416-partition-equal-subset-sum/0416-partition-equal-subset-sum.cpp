// class Solution {
// public:
//     bool solve(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){
    
//     int n=nums.size();
//     if(target==0) return true;
//     if(idx==nums.size()) return false;
    
//     if(dp[idx][target]!=-1) return dp[idx][target];

//     bool take=false;
//     if(nums[idx]<=target){
//     take=solve(idx+1,nums,target-nums[idx],dp);
//     }
 
//     bool nottake=solve(idx+1,nums,target,dp);

//     return dp[idx][target]=nottake || take;
//     }

//     bool canPartition(vector<int>& nums) {
//     int sm=0;
//     int n=nums.size();
    
//     for(int i=0;i<n;i++){
//     sm=sm+nums[i];
//     }
//     int target=sm/2;
//     vector<vector<int>>dp(n,vector<int>(target+1,-1));

//     if(sm%2==0){
//     return solve(0,nums,target,dp);
//     }
//     else{
//         return false;
//     }
        
//     }
// };









class Solution {
public:
    

    bool canPartition(vector<int>& nums) {
    int sm=0;
    int n=nums.size();
    
    for(int i=0;i<n;i++){
    sm=sm+nums[i];
    }
    int target=sm/2;
    vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
    
    if(sm%2!=0){
    return false;
    }
    for (int i = 0; i <= n; i++){
   dp[i][0] = true;
    }
    


    for(int idx=n-1;idx>=0;idx--){
    for(int t=1;t<=target;t++){
    
    bool take=false;
    if(nums[idx]<=t){
    take=dp[idx+1][t-nums[idx]];
    }
    bool not_take=dp[idx+1][t];
 
    dp[idx][t]=take || not_take;
    }
    }
    return dp[0][target];
        
    }
};