class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>v;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
    int j=i+1;
    int k=n-1;
    if(i>0 && nums[i]==nums[i-1]) continue;

    while(j<k){
    
    int sm=nums[i]+nums[j]+nums[k];
    if(sm==0){
    v.push_back({nums[i],nums[j],nums[k]});
    k--,j++;  
    
    
    while(j<k && nums[j]==nums[j-1]) j++;
    while(j<k && nums[k]==nums[k+1]) k--;
    }

    else if(sm<0) j++;
    else{
        k--;
    }
    }
    }   
    return v;
    }
};