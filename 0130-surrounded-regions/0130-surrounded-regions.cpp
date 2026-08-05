class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
    
    int m=board.size();
    int n=board[0].size();

    vis[row][col]=1;
     
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    for(int i=0;i<4;i++){
    int nrow=delrow[i]+row;
    int ncol=delcol[i]+col;

    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
    vis[nrow][ncol]=1;
    dfs(nrow,ncol,board,vis);
    }
    }

    }


    void solve(vector<vector<char>>& board){
    int m=board.size();
    int n=board[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    // row top
    int frstrow=0;
    for(int j=0;j<n;j++){
    if(board[frstrow][j]=='O'){
    dfs(frstrow,j,board,vis);
    }
    }
    
    int lastrow=m-1;
    for(int j=0;j<n;j++){
    if(board[lastrow][j]=='O'){
    dfs(lastrow,j,board,vis);
    }
    }

    int firstcol=0;
    for(int i=0;i<m;i++){
    if(board[i][firstcol]=='O'){
    dfs(i,firstcol,board,vis);
    }
    }


    int lastcol=n-1;
    for(int i=0;i<m;i++){
    if(board[i][lastcol]=='O'){
    dfs(i,lastcol,board,vis);
    }
    }

    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    if(vis[i][j]==0 && board[i][j]=='O'){
    board[i][j]='X';
    }
    else if(vis[i][j]==1 && board[i][j]=='O') continue;
    }
    }
    
    }
};