class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    int lo=1;
    int hi=n-2;
    if(n==1) return 0;
    
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
    return mid;
     }

    else if(nums[mid]>nums[mid-1]){
    lo=mid+1;
    }
    else if(nums[mid]>nums[mid+1]){
    hi=mid-1;
     }
    else hi=mid-1;
    }
    return -1;
    }
};