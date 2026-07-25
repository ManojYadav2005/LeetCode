class Solution {
public:
    int func(vector<int>&nums,int k){
    int n=nums.size();
    int l=0;
    int cnt=0;
    unordered_map<int,int>mpp;

    for(int r=0;r<n;r++){
    mpp[nums[r]]++;

    while(mpp.size()>k){
    mpp[nums[l]]--;
    if(mpp[nums[l]]==0) mpp.erase(nums[l]);
    l++;
    }
    cnt=cnt+(r-l+1);
    }
    return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

    int n=nums.size();

    return func(nums,k)-func(nums,k-1);  
    }
};