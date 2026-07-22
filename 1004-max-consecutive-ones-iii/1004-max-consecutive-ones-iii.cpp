class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();  
    int maxlen=0;
    int l=0;
    unordered_map<int,int>mpp; 

    for(int r=0;r<n;r++){
    mpp[nums[r]]++;  
    while(mpp[0]>k){
    mpp[nums[l]]--;
    l++;
    }
    maxlen=max(maxlen,r-l+1);

    } 
    return maxlen;
    }
};