class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n=nums.size();

    int xoR=0;
    for(int i=0;i<n;i++){
    xoR=xoR^nums[i];
    } 
    return xoR;
    }
};