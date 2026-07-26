// class Solution {
// public:
//     int solve(int n,vector<int>&dp){
    
//     if(n<0) return 0;

//     if(dp[n]!=-1) return dp[n]; // reduce repeating calls ko,jo visit ho chuki hai,Each value is calculated only once.
//     if(n==0){
//     return 1;
//     } 
//     int step1=solve(n-1);
//     int step2=solve (n-2);

//     return dp[n]=step1+step2; 
//     }

//     int climbStairs(int n) {
//     vector<int>dp(n+1,-1);
//     return solve(n,dp);
//     }
// };


class Solution {
public:

 int climbStairs(int n) {
   
   if(n==1 || n==2 || n==3) return n;
   
   vector<int>dp(n+1);
   dp[0]=0;
   dp[1]=1;
   dp[2]=2;

   for(int i=3;i<=n;i++){
   dp[i]=dp[i-1]+dp[i-2];
   }
    return dp[n];
  }
};