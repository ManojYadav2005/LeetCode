class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    int n=triangle.size();
    if(row==n-1) return triangle[row][col];
    if(dp[row][col]!=10000000) return dp[row][col];// 

   

    int down=triangle[row][col]+solve(row+1,col,triangle,dp);
    int downrght=triangle[row][col]+solve(row+1,col+1,triangle,dp);
    
    
    return dp[row][col]=min(down,downrght);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,10000000));
    return solve(0,0,triangle,dp);    
    }
};