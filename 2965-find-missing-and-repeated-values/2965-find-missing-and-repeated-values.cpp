class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

     int n=grid.size();
     
     int missing=-1;
     int repeat=-1;
     for(int num=1;num<=n*n;num++){
     int cnt=0;
     for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
     
     if(num==grid[i][j]){
     cnt++;
     }
     }
     }
     if(cnt==2){
     repeat=num; }
     if(cnt==0){
     missing=num;}

     } 
     return {repeat,missing};  
    }
};