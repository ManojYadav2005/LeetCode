// class Solution {
// public:
//     int solve(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    
//     if(i<0 || i>=n || j<0 || j>=m || obstacleGrid[i][j]==1){
//     return 0;
//     }
//     if(i==n-1 && j==m-1){
//     return 1;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];

//     int right=solve(i,j+1,m,n,obstacleGrid,dp);
//     int down=solve(i+1,j,m,n,obstacleGrid,dp);
    
//     dp[i][j]=right+down;
//     return dp[i][j];
//     }


//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int n=obstacleGrid.size();
//     int m=obstacleGrid[0].size();

//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     return solve(0,0,m,n,obstacleGrid,dp); 
//     }
// };











class Solution {
public:
   


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();

    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    // fill col 1 with these conditions
    for(int col=0;col<m;col++){
    if(col>=1 && obstacleGrid[0][col-1]==1){
    dp[0][col]=0;
    obstacleGrid[0][col]=1;
    }
    else if(obstacleGrid[0][col]==1){
    dp[0][col]=0;
    }
    else{
    dp[0][col]=1;
    }
    }
    
     for(int row=0;row<n;row++){
    if(row>=1 && obstacleGrid[row-1][0]==1){
    dp[row][0]=0;
    obstacleGrid[row][0]=1;
    }
    else if(obstacleGrid[row][0]==1){
    dp[row][0]=0;
    }
    else{
    dp[row][0]=1;
    }
    }

    for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
    if(obstacleGrid[i][j]==1){
    dp[i][j]=0;
    }  
    else{
    dp[i][j]=dp[i][j-1]+dp[i-1][j]; }  
    }
    }
    return dp[n-1][m-1];
    }
};