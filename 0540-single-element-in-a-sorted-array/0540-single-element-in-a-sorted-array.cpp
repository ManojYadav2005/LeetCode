class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

     int n=nums.size();
     int lo=0;
     int hi=n-1;

     while(lo<hi){

     int mid=lo+(hi-lo)/2;
     

     if(nums[mid]==nums[mid+1]){
     int check=hi-mid;
     
     if(check%2==0){
     lo=mid+2; } // same hoga na isliye +2
     else{
     hi=mid-1; }
     }


    else if(nums[mid]!=nums[mid+1]){
     int iseven=hi-mid;
     
     if(iseven%2==0){
     hi=mid;}
     else{
     lo=mid+1;
      }
     }

     }
     return nums[hi];   
    }
};