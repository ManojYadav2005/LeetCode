class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
    int n=nums.size();
    
    int mini=INT_MAX;
    int maxi=INT_MIN;
    
    int idxmin=-1;
    int idxmax=-1;
    for(int i=0;i<n;i++){
    if(mini>nums[i]){
    idxmin=i;
    mini=nums[i];
    }
    if(maxi<nums[i]){
    idxmax=i;
    maxi=nums[i];
    }
    }
    int l=min(idxmin,idxmax);
    int r=max(idxmin,idxmax);
    
    int front=r+1;
    int back=n-l;
    int both=(l+1)+(n-r);
    return min(front, min(back, both));
    }
};