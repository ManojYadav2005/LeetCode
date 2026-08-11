class Solution {
public:
    long long int solve(int mid,vector<int>& piles,int n){
    long long int sm=0;
    for(int i=0;i<n;i++){
    sm=sm+(piles[i]+mid-1)/mid;
    }
    return sm;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
    
    int n=piles.size();

    long long int lo=1;
     int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    maxi=max(maxi,piles[i]);
    }
    long long int hi=maxi; 
    
    while(lo<=hi){
    long long int mid=lo+(hi-lo)/2;
    
    long long int findmin=solve(mid,piles,n);
    if(findmin<=h){
    hi=mid-1;
    }
    else{
    lo=mid+1;
    }
    }  
    return lo; 
    }
};