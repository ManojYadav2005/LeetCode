class Solution {
public:
    int solve(int capacity,vector<int>& weights,int n){
    int cnt=1;
    int sm=0;
    for(int i=0;i<n;i++){
    if(sm+weights[i]<=capacity){
    sm=sm+weights[i];
    } 
    else {
    sm=weights[i]; 
    cnt++;}
    }
    return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {

    int n=weights.size();
    int lo=1;
    int sm=0;
    for(int i=0;i<n;i++){
    sm=sm+weights[i];
    }   
    int hi=sm;
    int ans=0;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;

    int find=solve(mid,weights,n);

    if(find<=days){
    hi=mid-1;
    ans=mid;
    }
    else{
    lo=mid+1;
    }
    } 
     return ans;
    }
};