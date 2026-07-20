class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
     
     int m=grid.size();
     int n=grid[0].size();
     
     for(int shift=0;shift<k;shift++) {

     vector<vector<int>> v(m,vector<int>(n,0));
     
     v[0][0]=grid[m-1][n-1];

     for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
    
     if(i==m-1 && j==n-1)
     continue;
     if(j==n-1){
     v[i+1][0]=grid[i][n-1];
     }
     else{
     v[i][j+1]=grid[i][j];}
     }
     
     }
     grid=v; 
     }
       return grid;
    }
};