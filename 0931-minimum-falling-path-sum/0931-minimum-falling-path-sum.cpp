// class Solution {
// public:
//    int solve(vector<vector<int>>& matrix,int row,int col){
//    int minsm=INT_MAX;
//    int n=matrix.size();

//    if(row==n-1) return matrix[row][col];
//    int sm=matrix[row][col];

//    if(row+1<n && col-1>=0){
//    minsm=min(minsm,sm+solve(matrix,row+1,col-1));
//    }
//    if(row+1<n){
//    minsm=min(minsm,sm+solve(matrix,row+1,col));
//    }
//    if(row+1<n && col+1<n){
//    minsm=min(minsm,sm+solve(matrix,row+1,col+1));
//    }
//    return minsm;
//    }


//     int minFallingPathSum(vector<vector<int>>& matrix) {
//      int n=matrix.size();
     
//      int minsm=INT_MAX;
//      int row=0;
//      for(int col=0;col<n;col++){
//      minsm=min(minsm,solve(matrix,row,col));
//      } 
//      return minsm;  
//     }
// };











class Solution {
public:
   int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
   int minsm=INT_MAX;
   int n=matrix.size();
   
   
   if(dp[row][col] != 100000) return dp[row][col];
   if(row==n-1) return dp[row][col]=matrix[row][col];
   
   int sm=matrix[row][col];


   if(row+1<n && col-1>=0){
   minsm=min(minsm,sm+solve(matrix,row+1,col-1,dp));
   }
   if(row+1<n){
   minsm=min(minsm,sm+solve(matrix,row+1,col,dp));
   }
   if(row+1<n && col+1<n){
   minsm=min(minsm,sm+solve(matrix,row+1,col+1,dp));
   }
   return dp[row][col]=minsm;
   }


    int minFallingPathSum(vector<vector<int>>& matrix) {
     int n=matrix.size();
     
     vector<vector<int>>dp(n,vector<int>(n,100000));
     int minsm=INT_MAX;
     int row=0;
     for(int col=0;col<n;col++){
     minsm=min(minsm,solve(matrix,row,col,dp));
     } 
     return minsm;  
    }
};


