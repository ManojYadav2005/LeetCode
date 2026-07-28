class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    
    if(i<0 || i>=n || j<0 || j>=m || obstacleGrid[i][j]==1){
    return 0;
    }
    if(i==n-1 && j==m-1){
    return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int right=solve(i,j+1,m,n,obstacleGrid,dp);
    int down=solve(i+1,j,m,n,obstacleGrid,dp);
    
    dp[i][j]=right+down;
    return dp[i][j];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(0,0,m,n,obstacleGrid,dp); 
    }
};