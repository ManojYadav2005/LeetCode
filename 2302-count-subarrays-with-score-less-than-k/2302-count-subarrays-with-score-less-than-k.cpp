class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
     int n=nums.size();

    long long int l=0;
    long long int sm=0;
    long long int cntlen=0;
     for(int r=0;r<n;r++){
     sm=sm+nums[r];
     int len=r-l+1;

     while(sm*(long long)len>=k){
     sm=sm-nums[l];
     l++;
     len--;
     }
     cntlen=cntlen+(r-l+1);
     }  
     return cntlen; 
    }
};