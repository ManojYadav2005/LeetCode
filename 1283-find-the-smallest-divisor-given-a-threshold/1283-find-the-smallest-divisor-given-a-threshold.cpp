class Solution {
public:
    int check(int mid,int n,vector<int>& nums, int threshold){
    int sm=0;
    for(int i=0;i<n;i++){
    if(nums[i]%mid==0){
    sm=sm+nums[i]/mid;
    }
    else{
    sm=sm+nums[i]/mid+1; }
    }
    return sm;
    }



    int smallestDivisor(vector<int>& nums, int threshold) {
    int n=nums.size();

    int lo=1;
    int hi=*max_element(nums.begin(),nums.end());
    int res=-1; 
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
     
    int find=check(mid,n,nums,threshold);
    
    if(find<=threshold){
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