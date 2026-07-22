class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
     int n=nums.size();
     int maxlen=0;
     unordered_map<int,int>mpp;
     int sum=0;
     int l=0;
     for(int r=0;r<n;r++){
     
     while(mpp[nums[r]]>=1){
     mpp[nums[l]]--;
     sum=sum-nums[l];
     l++;
     }
     sum=sum+nums[r];
     mpp[nums[r]]++;
     maxlen=max(maxlen,sum);

     }   
     return maxlen;
    }
};