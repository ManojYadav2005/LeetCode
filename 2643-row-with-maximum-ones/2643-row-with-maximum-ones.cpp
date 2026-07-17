class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

     int n=mat.size();
     int m=mat[0].size();
     
     int maxi=INT_MIN;
     int idx;
     for(int i=0;i<n;i++){
     int cnt1=0;
     for(int j=0;j<m;j++){
     if(mat[i][j]==1){
     cnt1++;
     }
     if(maxi<cnt1){
     maxi=max(maxi,cnt1);
     idx=i;
     }
     }
     } 
     return {idx,maxi};  
    }
};