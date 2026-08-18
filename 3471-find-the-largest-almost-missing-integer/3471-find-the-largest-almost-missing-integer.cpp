class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    int n=nums.size();
    
    unordered_map<int,int>mpp;
    for(auto it:nums) mpp[it]++;
    
    if(k==n) return *max_element(nums.begin(), nums.end());
    
    if(k==1){
    int maxi=-1;
    for(auto it:mpp){
    if(it.second==1) maxi=max(maxi,it.first);
    }
    return maxi;
    }    
   
    
    int first=nums[0];
    int last=nums[n-1];
    int maxi=-1;
  
    if(mpp[first]==1) maxi=max(maxi,first);
    if(mpp[last]==1) maxi=max(maxi,last);
    
     return maxi;
    }
};