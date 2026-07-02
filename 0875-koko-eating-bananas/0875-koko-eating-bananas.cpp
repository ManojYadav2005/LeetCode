class Solution {
public:
    int check(int mid,int n,vector<int>&piles){
    
    int totlhrs=0;
    for(int i=0;i<n;i++){
    totlhrs+=(piles[i]+mid-1)/mid;
    }
    return totlhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

    int n=piles.size();
    int lo=1;
    int hi=*max_element(piles.begin(),piles.end());
    
    while(lo<hi){
    int mid=lo+(hi-lo)/2;

    int find=check(mid,n,piles);

    if(find<=h){
    hi=mid;
    }
    else{
    lo=mid+1;
    }

    }
    return lo;
    }
};