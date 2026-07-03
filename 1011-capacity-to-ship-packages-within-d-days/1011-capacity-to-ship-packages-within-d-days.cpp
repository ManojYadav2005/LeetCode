class Solution {
public:
     int check(int mid,int days,vector<int>& weights, int n){
     int day=1;
     int load=0;

    for(int i=0;i<n;i++){
    if(load+weights[i]>mid) {
    day++;
    load=weights[i]; 
    }
    else{
    load=load+weights[i];
    }
    }
    return day;
     }

    int shipWithinDays(vector<int>& weights, int days) {

     int n=weights.size();
     int sum=0;
    int maxi=0;

    for(int i=0;i<n;i++){
    sum+=weights[i];
    maxi=max(maxi,weights[i]);
    }

     int lo=maxi;
     int hi=sum;

     int ans=0;
     while(lo<=hi){

     int mid=lo+(hi-lo)/2;

     int find=check(mid,days,weights,n);
     if(find<=days){
       ans=mid;
      hi=mid-1;
     }
     else{
     lo=mid+1;
     }
     } 
     return ans;

    }
};