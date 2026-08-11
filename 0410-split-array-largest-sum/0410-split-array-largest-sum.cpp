class Solution {
public:
    int solve(int capacity,vector<int>& nums,int k,int n){
    int sm=0;
    int cnt=1;

    for(int i=0;i<n;i++){
    if(sm+nums[i]<=capacity){
    sm=sm+nums[i];
    }
    else{
    sm=nums[i];
    cnt++;
    }
    }
    return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
    int lo=*max_element(nums.begin(),nums.end());
    
    int ans=0;
    int n=nums.size();
    int sm=0;
    for(int i=0;i<n;i++){
    sm=sm+nums[i];
    }
    int hi=sm;

    while(lo<=hi){
    int mid=lo+(hi-lo)/2;

    int find=solve(mid,nums,k,n);
    if(find<=k){
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