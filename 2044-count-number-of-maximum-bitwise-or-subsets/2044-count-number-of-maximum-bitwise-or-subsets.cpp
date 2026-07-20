class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

    int n=nums.size();
    int orr=0;
    for(int i=0;i<n;i++){
    orr=orr|nums[i];
    } 

    int cnt=0;
    int subset=1<<n;
    for(int num=0;num<subset;num++){
    int nwor=0;
    for(int i=0;i<n;i++){
    if(num&(1<<i)){
    nwor=nwor|nums[i];
    }
    }
    if(nwor==orr)
    cnt++;
    } 
    return cnt;
    }
};