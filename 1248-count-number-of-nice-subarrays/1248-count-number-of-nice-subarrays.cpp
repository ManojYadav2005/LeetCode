class Solution {
public:
    int func(vector<int>&nums,int k){
    int l=0;
    int n=nums.size();
    int r=0;
    int cnt=0;
    int sm=0;
    int cntlen=0;
    while(r<n){
    
    if(nums[r]%2==1){
    cnt++;
    }
    while(cnt>k){
    if(nums[l]%2==1){
    cnt--;
    }   
    l++;
    }
    cntlen=cntlen+(r-l+1);
    r++;
    }
    return cntlen;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
    return func(nums,k)-func(nums,k-1);   
    }
};