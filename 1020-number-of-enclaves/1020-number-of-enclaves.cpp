class Solution {
public:
      void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
    
    int m=grid.size();
    int n=grid[0].size();

    vis[row][col]=1;
     
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    for(int i=0;i<4;i++){
    int nrow=delrow[i]+row;
    int ncol=delcol[i]+col;

    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
    vis[nrow][ncol]=1;
    dfs(nrow,ncol,grid,vis);
    }
    }

    }

    int numEnclaves(vector<vector<int>>& grid) {
    
    int m=grid.size();
    int n=grid[0].size();

     vector<vector<int>>vis(m,vector<int>(n,0));
    // row top
    int frstrow=0;
    for(int j=0;j<n;j++){
    if(grid[frstrow][j]==1){
    dfs(frstrow,j,grid,vis);
    }
    }
    
    int lastrow=m-1;
    for(int j=0;j<n;j++){
    if(grid[lastrow][j]==1){
    dfs(lastrow,j,grid,vis);
    }
    }

    int firstcol=0;
    for(int i=0;i<m;i++){
    if(grid[i][firstcol]==1){
    dfs(i,firstcol,grid,vis);
    }
    }


    int lastcol=n-1;
    for(int i=0;i<m;i++){
    if(grid[i][lastcol]==1){
    dfs(i,lastcol,grid,vis);
    }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(vis[i][j]==0 && grid[i][j]==1){
    cnt++;
    }
    else if(vis[i][j]==1 && grid[i][j]==1) continue;
    }
    } 
     return cnt;
    }
};