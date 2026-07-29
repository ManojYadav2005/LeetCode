class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
    int m=grid.size();
    int n=grid[0].size();
    if(i==m-1 && j==n-1) return grid[i][j];

    if(dp[i][j]!=-1) return dp[i][j];
    
    if(i==m-1) return dp[i][j]=grid[i][j]+solve(i,j+1,grid,dp); // right move only
    else if(j==n-1) return dp[i][j]=grid[i][j]+solve(i+1,j,grid,dp); // move left only
    else return dp[i][j]=grid[i][j]+min(solve(i,j+1,grid,dp),solve(i+1,j,grid,dp));
    
    }

    int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();    
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,grid,dp);    
    }
};