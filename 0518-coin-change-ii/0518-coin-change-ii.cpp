// class Solution {
// public:
//     int solve(int idx,int amount,vector<int>& coins,vector<vector<int>>&dp){
    
//     if(idx==0){
//     if(amount%coins[0]==0) return 1;
//     else return 0;
//     }
//     if(dp[idx][amount]!=-1) return dp[idx][amount];

//     int not_take=solve(idx-1,amount,coins,dp);
//     int take=0;
    
//     if(coins[idx]<=amount){
//     take=solve(idx,amount-coins[idx],coins,dp);
//     }
//     return dp[idx][amount]=take+not_take;

//     }

//     int change(int amount, vector<int>& coins) {

//     int n=coins.size();
//     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//     return solve(n-1,amount,coins,dp);    
//     }
// };



class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        // Check if amount is impossible
        int g = 0;
        for (int c : coins) {
            g = gcd(g, c);
        }

        if (amount % g != 0)
            return 0;


        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));


        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }


        for (int idx = 1; idx < n; idx++) {

            for (int t = 0; t <= amount; t++) {

                long long notTake = dp[idx-1][t];

                long long take = 0;

                if (coins[idx] <= t)
                    take = dp[idx][t - coins[idx]];

                dp[idx][t] = take + notTake;
            }
        }

        return dp[n-1][amount];
    }
};