class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

    int n=isWater.size();
     int m=isWater[0].size();

     queue<pair<int,int>>q;
     vector<vector<int>>res(n,vector<int>(m,-1));

     for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
     if(isWater[i][j]==1){
     res[i][j]=0;
     q.push({i,j});
     }
     }
     }   

     int delrow[4]={-1,0,1,0};
     int delcol[4]={0,1,0,-1};

     while(!q.empty()){
     int row=q.front().first;
     int col=q.front().second;

     q.pop();

     for(int i=0;i<4;i++){
     int nrow=row+delrow[i];
     int ncol=col+delcol[i];

     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && res[nrow][ncol]==-1){
     res[nrow][ncol]=res[row][col]+1;
     q.push({nrow,ncol});
     }
     }

     }
     return res;
    }
};