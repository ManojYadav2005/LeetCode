class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int lo=0;
    int n=arr.size();
    int hi=n-1;
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    long long int miss=arr[mid]-(mid+1);

    if(miss<k){
    lo=mid+1;
    }
    else{
    hi=mid-1;
    }
    }     
    return lo+k;
    }
};