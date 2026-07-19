class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     int n=nums.size();

     int xOr=0;
     for(int i=0;i<n;i++){
     xOr=xOr^nums[i];
     } 
long long mask = (long long)xOr & (-(long long)xOr);     
     int grpa=0;
     int grpb=0;

     for(int i=0;i<n;i++){
     if((mask&nums[i])!=0){
     grpa=grpa^nums[i];
     }
     else{
      grpb=grpb^nums[i];  
     }
     }
     return {grpa,grpb};
    }
};