// class Solution {
// public:
    
//     bool solve(int currston_idx, int prevjp,vector<int>& stones,unordered_map<int,int>& mpp){
    
//     if(currston_idx == stones.size()-1)return true;
    
//     if (dp[currston_idx][prevjp] != -1) return dp[currston_idx][prevjp];
//     bool result=false;

//     for(int nxtjmp=prevjp-1;nxtjmp<=prevjp+1;nxtjmp++){
//     int nxtston=stones[currston_idx]+nxtjmp;
    
//     if (nxtjmp<= 0) continue;

//     if(mpp.find(nxtston)!=mpp.end()){
//     result=result||solve(mpp[nxtston],nxtjmp,stones,mpp);
    
//     }
//     }
//     return result;
//     }


     
//     bool canCross(vector<int>& stones) {
   
//     if (stones[1] != 1) return false;
//     unordered_map<int,int>mpp;
//     for (int i = 0; i < stones.size(); i++) {
//     mpp[stones[i]] = i;
//     } 
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return solve(1,1,stones,mpp);
   
//     }
// };





class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int currston_idx,int prevjp,vector<int>& stones,unordered_map<int,int>& mpp,vector<vector<int>>& dp)
    {
        if(currston_idx==stones.size()-1)return true;

        if(dp[currston_idx][prevjp]!= -1) return dp[currston_idx][prevjp];

        bool result=false;

        for(int nxtjmp=prevjp-1;nxtjmp<=prevjp+1;nxtjmp++){

        if(nxtjmp<=0)continue;

        int nxtston=stones[currston_idx] + nxtjmp;

        if (mpp.find(nxtston) != mpp.end()) {
        result=result|| solve(mpp[nxtston], nxtjmp, stones, mpp,dp);

        if(result) break;
        }
        }
        return dp[currston_idx][prevjp] = result;
    }

    bool canCross(vector<int>& stones) {

        if(stones[1]!=1) return false;

        unordered_map<int,int>mpp;

        for(int i=0;i<stones.size();i++)
        mpp[stones[i]]=i;

        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(1,1,stones,mpp,dp);
    }
};