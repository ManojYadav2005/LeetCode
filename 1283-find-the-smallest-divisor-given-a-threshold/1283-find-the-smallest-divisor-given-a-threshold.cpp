class Solution {
public:
    
    int solve(int mid,vector<int>& nums,int n){
    int sm=0;
    for(int i=0;i<n;i++){
    sm=sm+(nums[i]+mid-1)/mid;
    }
    return sm;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {

    int n=nums.size();
    int lo=1;
    int hi=*max_element(nums.begin(),nums.end());
    int ans=-1;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    
    int find=solve(mid,nums,n);
    if(find<=threshold){
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