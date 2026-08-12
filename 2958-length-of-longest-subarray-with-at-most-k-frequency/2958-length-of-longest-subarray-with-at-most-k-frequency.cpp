class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

    int n=nums.size();
    map<int,int>mpp;
    int j=0;
    int i=0;
    int mxlen=0;
    while(j<n){
    mpp[nums[j]]++;

    while(mpp[nums[j]]>k){
    mpp[nums[i]]--;
    i++;
    }
    mxlen=max(mxlen,j-i+1);
    j++;
    }
    return mxlen;  
    }
};