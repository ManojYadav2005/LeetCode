class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n=nums.size();
     int cnt=0;
     vector<int>v;
     for(int i=0;i<n;i++){
     if(nums[i]==0){
     cnt++;
     }
     if(nums[i]!=0){
     v.push_back(nums[i]);
     }
     }
     for(int i=0;i<cnt;i++){
     v.push_back(0);
     } 
     
     for(int i=0;i<n;i++){
     nums[i]=v[i];
     } 
    }
};