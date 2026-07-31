// class Solution {
// public:
//     int solve(int idx,vector<int>& coins,int target,vector<vector<int>>&dp){
    
//     if(idx==0){
//     if(target%coins[0]==0) return target/coins[0];
//     else return 1e9;
//     }

//     if(dp[idx][target]!=-1) return dp[idx][target];
    


//     int not_take=0+solve(idx-1,coins,target,dp);
//     int take=INT_MAX;

//     if(coins[idx]<=target){
//     take=1+solve(idx,coins,target-coins[idx],dp);
//     }
//     return dp[idx][target]=min(take,not_take);
//     }

//     int coinChange(vector<int>& coins, int amount) {
    
//     int n=coins.size();
//     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    
//     int ans=solve(n-1,coins,amount,dp);
//     if(ans >= 1e9) return -1;  
//     return ans; 
//     }
// };












class Solution {
public:
 
    int coinChange(vector<int>& coins, int amount) {
    
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    
    for(int t=0;t<=amount;t++){
    if(t%coins[0]==0) dp[0][t]=t/coins[0];
    else dp[0][t]=1e9;
    }


    for(int idx=1;idx<n;idx++){
    for(int t=0;t<=amount;t++){

    int not_take=dp[idx-1][t];
    int take=1000000001;
    if(coins[idx]<=t){
    take=1+dp[idx][t-coins[idx]];
    }
    dp[idx][t]=min(take,not_take);
    }
    }

    if(dp[n-1][amount]>=1e9) return -1;
    
    return dp[n-1][amount];
    
    }
};