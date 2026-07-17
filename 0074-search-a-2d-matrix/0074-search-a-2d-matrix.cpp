class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    vector<int>v;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    v.push_back(matrix[i][j]);
    }
    } 
    int k=v.size();

    int lo=0;
    int hi=k-1;

    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    
    if(v[mid]==target){
        return true;
    }
    if(v[mid]>target){
    hi=mid-1;
    }
    else{
    lo=mid+1;
    }
    }  
    return false;
    }
};