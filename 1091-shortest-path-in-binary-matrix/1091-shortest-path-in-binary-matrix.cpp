class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n=grid.size();
    
    if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
    if(n==1) return 1;

    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    q.push({{0,0},1});
    dist[0][0]=1;
    
    int delrow[8]={-1,-1,-1,0,0,1,1,1};
    int delcol[8]={-1,0,1,-1,1,-1,0,1};
    while(!q.empty()){
    auto it=q.front();
    int row=it.first.first;
    int col=it.first.second;
    int dis=it.second;

    q.pop();

    for(int i=0;i<8;i++){
    int nrow=delrow[i]+row;
    int ncol=delcol[i]+col;

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dist[nrow][ncol]==1e9 && grid[nrow][ncol]==0){
    dist[nrow][ncol]=dis+1;
    q.push({{nrow,ncol},dis+1});
    }
    }
    }  
    if(dist[n-1][n-1]==1e9) return -1;  
    return dist[n-1][n-1];
    }
};