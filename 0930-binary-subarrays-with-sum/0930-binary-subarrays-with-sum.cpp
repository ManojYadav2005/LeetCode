class Solution {
public:
    int func(vector<int>&nums,int goal){
     int n=nums.size();

     int l=0;
     int cnt=0;
     int sm=0;
     int r=0;

     if(goal<0) return 0;

     while(r<n){
     
     sm=sm+nums[r];

     while(sm>goal){
     sm=sm-nums[l];
     l++;
     }
     cnt=cnt+(r-l+1);
     r++;
     
     }  
     return cnt; 

    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
     int n=nums.size();
     return func(nums,goal)-func(nums,goal-1);
    
    }
};