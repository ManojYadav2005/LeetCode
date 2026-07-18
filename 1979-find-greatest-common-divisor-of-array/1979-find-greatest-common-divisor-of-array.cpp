class Solution {
public:
    // int gcd(int mini,int maxi){
    //  int idx;
    //  for(int i=2;i<maxi;i++){
    //  if(mini%i==0 && maxi%i==0){
    //  idx=i;
    //  return idx;
    //  }
    //  }
    //  return 1;
    // }

    int findGCD(vector<int>& nums) {
      int n=nums.size();
      int mini=INT_MAX;
      int maxi=INT_MIN;

      for(int i=0;i<n;i++){
      mini=min(nums[i],mini);
      maxi=max(maxi,nums[i]);
      }
      
     return  gcd(mini,maxi);
    }
};