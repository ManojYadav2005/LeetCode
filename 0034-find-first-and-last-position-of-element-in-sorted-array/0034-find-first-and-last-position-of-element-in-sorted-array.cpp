class Solution {
public:

    int ub(vector<int>& nums,int target){
    int lo=0;
    int n=nums.size();
    int hi=n-1;
    int idx=-1;

    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(nums[mid]<=target){
    idx=mid;
    lo=mid+1;
    }
    else{
     hi=mid-1;   
     }
    }
    return idx;
    }

    int lb(vector<int>& nums, int target){
    int lo=0;
    int n=nums.size();
    int hi=n-1;
    int idx=-1;

    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(nums[mid]>=target){
    hi=mid-1;
    idx=mid;
    }
    else{
    lo=mid+1;}
    }
    return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
     int first=lb(nums,target);
     int second=ub(nums,target);

     if(first==-1 || nums[first]!=target)
     return {-1,-1};
     return {first,second};
    }
};