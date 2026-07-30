class Solution {
public:

    int solve(int mid,vector<int>& weights, int days){
    int cnt=1;
    int sm=0;
    int n=weights.size();

    for(int i=0;i<n;i++){
    if(sm+weights[i]<=mid){
    sm=sm+weights[i];
    } 
    else{
    cnt++;   
    sm=weights[i];

    }  
    }
    return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {


    int n=weights.size();
    int sm=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    sm=sm+weights[i];
    maxi=max(maxi,weights[i]);
    }
    int lo=maxi;
    int hi=sm;    
    int ans=0;

    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    
    int res=solve(mid,weights,days);
    if(res<=days){
    hi=mid-1;
    ans=mid;
    }
    else if(res>=days){
    lo=mid+1;
    
    }
    }
    return ans;
    }
};