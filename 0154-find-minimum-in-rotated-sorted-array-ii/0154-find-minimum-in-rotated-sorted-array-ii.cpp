class Solution {
public:
    int findMin(vector<int>& nums) {
     int n=nums.size();
     int lo=0;
     int hi=n-1;
     int idx=0;

     while(lo<=hi){
     
     
     while(lo<hi && nums[lo]==nums[lo+1]) lo++;
     while(hi>lo && nums[hi]==nums[hi-1]) hi--;
     
     int mid=lo+(hi-lo)/2;
     
     if(nums[mid]<nums[idx]){
     idx=mid;
     }   
     if(nums[hi]<nums[mid]){ // rotated
       lo=mid+1;
     }
     else{
        hi=mid-1;
     }
     }  
     return nums[idx]; 
    }
};