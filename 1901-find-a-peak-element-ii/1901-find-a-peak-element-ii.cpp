class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();  

      for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
      
       int up=(i==0) ? -1 : mat[i-1][j];
       int down=(i==n-1) ? -1 : mat[i+1][j];
       int left=(j==0) ? -1 : mat[i][j-1];
       int right=(j==m-1) ? -1 : mat[i][j+1];
      
        if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>left && mat[i][j]> right){
       return {i,j};
      }  
      }
      }
      return {};
    }
};