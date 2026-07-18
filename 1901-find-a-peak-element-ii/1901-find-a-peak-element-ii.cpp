class Solution {
public:
    int findMax(vector<vector<int>>& mat,int n,int m,int mid){
    int mxval=-1;
    int idx=-1;

    for(int i=0;i<n;i++){
    if(mat[i][mid]>mxval){
    mxval=mat[i][mid];
    idx=i;
    }   
    }
    return idx;
    }

      vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();  
      
      int lo=0;
      int hi=m-1;

      while(lo<=hi){
      int mid=(lo+hi)/2;

      int mxrowidx=findMax(mat,n,m,mid);

      int left=mid-1>=0 ? mat[mxrowidx][mid-1] : -1;
      int right=mid+1<m ? mat[mxrowidx][mid+1] : -1;
      
      if(mat[mxrowidx][mid]>left && mat[mxrowidx][mid]>right){
      return {mxrowidx,mid};
       }
       else if(mat[mxrowidx][mid]<left){
       hi=mid-1;
       }
      else{
       lo=mid+1; }
      }
      return {};
    }
};