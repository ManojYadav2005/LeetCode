class Solution {
public:
    bool Isallocate(vector<int>&nums,int k,int mid,int n){
    
    int cnt=1;
    int pgs=0;
    for(int i=0;i<n;i++){
    if(pgs+nums[i]<=mid){
    pgs+=nums[i];
    }
    else{
    pgs=nums[i];
    cnt++;
    }
    }
    if(cnt<=k) return true;
    else return false;
    }

    int splitArray(vector<int>& nums, int k) {

     int n=nums.size();
     int sm=0;
     for(int i=0;i<n;i++){
     sm=sm+nums[i];
     }  

     int lo=*max_element(nums.begin(),nums.end());
     int hi=sm;
     int res=-1;
     while(lo<=hi){
     int mid=lo+(hi-lo)/2;

     if(Isallocate(nums,k,mid,n)==true){
     hi=mid-1;
     res=mid;
     }
     else{
        lo=mid+1;
     }
     } 
     return res;
    }
};