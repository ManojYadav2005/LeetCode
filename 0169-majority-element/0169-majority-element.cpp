class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n=nums.size();

     int cnt=1;
     int ele1=nums[0];

     for(int i=1;i<n;i++){
     if(nums[i]==ele1){
     cnt++;
     }
     if(cnt==0){
     ele1=nums[i];
     cnt++;
     }

    else if(nums[i]!=ele1){
     cnt--;
     }
    
     }
     return ele1;
    }
};