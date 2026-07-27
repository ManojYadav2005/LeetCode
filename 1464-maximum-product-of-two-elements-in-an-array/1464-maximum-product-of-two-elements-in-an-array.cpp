class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int maxi=INT_MIN;    
    for(int i=0;i<n;i++){
     int pro=nums[i]-1;   
    for(int j=i+1;j<n;j++){
    maxi=max(maxi,(pro)*(nums[j]-1));
    }
    }
    return maxi;
    }
};