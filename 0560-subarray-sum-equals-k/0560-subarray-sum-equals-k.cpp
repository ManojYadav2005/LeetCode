class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int>mpp;
    int n=nums.size();

    mpp[0]=1;

    int sm=0;
    int cnt=0;

    for(int i=0;i<n;i++){
    sm=sm+nums[i];
    int prefix=sm-k;

    if(mpp.find(prefix)!=mpp.end()){
    cnt=cnt+mpp[prefix];
    mpp[sm]++;
    }
    else{
    mpp[sm]++;
    }
    }
    return cnt;    
    }
};