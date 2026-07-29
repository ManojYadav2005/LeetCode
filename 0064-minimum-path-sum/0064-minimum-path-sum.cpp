// class Solution {
// public:
//     int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
//     int m=grid.size();
//     int n=grid[0].size();
//     if(i==m-1 && j==n-1) return grid[i][j]; // pehle recursion last tk pahuchega phir return karega 


//     if(dp[i][j]!=-1) return dp[i][j];
    
//     if(i==m-1) return dp[i][j]=grid[i][j]+solve(i,j+1,grid,dp); // right move only
//     else if(j==n-1) return dp[i][j]=grid[i][j]+solve(i+1,j,grid,dp); // move left only
//     else return dp[i][j]=grid[i][j]+min(solve(i,j+1,grid,dp),solve(i+1,j,grid,dp));
    
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//     int m=grid.size();
//     int n=grid[0].size();    
//     vector<vector<int>>dp(m,vector<int>(n,-1));
//     return solve(0,0,grid,dp);    
//     }
// };






class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
    
    int m=grid.size();
    int n=grid[0].size(); 

    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0]=grid[0][0];

    for(int col=1;col<n;col++){
    dp[0][col]=grid[0][col]+dp[0][col-1];
    }

    for(int row=1;row<m;row++){
    dp[row][0]=grid[row][0]+dp[row-1][0];
    }

    for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
    
    }
    }
    return dp[m-1][n-1];
    }
};

