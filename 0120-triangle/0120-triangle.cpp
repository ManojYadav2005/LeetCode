// class Solution {
// public:
//     int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>&dp){
//     int n=triangle.size();
//     if(row==n-1) return triangle[row][col];
//     if(dp[row][col]!=10000000) return dp[row][col];// 

   

//     int down=triangle[row][col]+solve(row+1,col,triangle,dp);
//     int downrght=triangle[row][col]+solve(row+1,col+1,triangle,dp);
    
    
//     return dp[row][col]=min(down,downrght);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//     int n=triangle.size();
//     vector<vector<int>>dp(n,vector<int>(n,10000000));
//     return solve(0,0,triangle,dp);    
//     }
// };




class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0]=triangle[0][0];
    int mini=INT_MAX;

    for(int row=1;row<n;row++){
    for(int col=0;col<=row;col++){
    int up=INT_MAX;
    int uprght=INT_MAX;
    if(col<row){
    up=triangle[row][col] + dp[row-1][col]; }
    if(col>0){
    uprght=triangle[row][col]+dp[row-1][col-1];}
    dp[row][col]=min(uprght,up);
    }
    
    }

    int minn=INT_MAX;
    for(int col=0;col<n;col++){
    minn=min(minn,dp[n-1][col]);
    }
    return minn;
    }
};