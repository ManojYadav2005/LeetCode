class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vmx(n);
        vector<int>vmin(n);
        
        vmx[0]=nums[0];
        for(int i=1;i<n;i++){
        vmx[i]=max(vmx[i-1],nums[i]);
        }
        vmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
        vmin[i]=min(vmin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
        if(vmx[i]-vmin[i]<=k){
        return i;
        }
        }
        return -1;
    }
};