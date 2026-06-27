class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

     int n=grid.size();
     int m=grid[0].size();
    if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
     if(n==1) return 1;
     vector<vector<int>>dist(n,vector<int>(m,1e9));

     queue<pair<int,pair<int,int>>>q;
      
     dist[0][0]=1; 
     q.push({1,{0,0}});
     
     int delrow[8] = {-1,-1,-1,0,0,1,1,1};
     int delcol[8] = {-1,0,1,-1,1,-1,0,1};

     while(!q.empty()){
     auto it=q.front();
     int dis=it.first;
     int row=it.second.first;
     int col=it.second.second;
     q.pop();

     for(int i=0;i<8;i++){
     int nrow=row+delrow[i];
     int ncol=col+delcol[i];

     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && 1+dis<dist[nrow][ncol]){
     dist[nrow][ncol]=1+dis;
     if(nrow==n-1 && ncol==m-1) return 1+dis;
     q.push({1+dis,{nrow,ncol}});
     }
     }

     }
     return -1;
    }
};