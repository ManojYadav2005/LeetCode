class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int n=nums.size();
     int maxi=INT_MIN;
     int mxlen=0;
     int res=INT_MIN;

     for(int i=0;i<n;i++){
     
     if(nums[i]>maxi){
     maxi=nums[i];
     res=0;
     mxlen=0;
     }
     
     if(maxi==nums[i]){
     mxlen++;
     }
     else if(nums[i]<maxi){
     mxlen=0;
     }
     res=max(mxlen,res);
     }
     return res;
    }
};