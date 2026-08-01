class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int>mpp;
     int n=nums.size();
     for(int i=0;i<n;i++){
     
      if(mpp.find(target-nums[i])!=mpp.end()){
     return {mpp[target-nums[i]],i};
     }
     else if(mpp.find(nums[i])==mpp.end()){
     mpp[nums[i]]=i;
     }
     } 
     return {};  
    }
};