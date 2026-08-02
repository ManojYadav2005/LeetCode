class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(nums.empty()) return 0;

    priority_queue<int>pq;

    for(int i=0;i<n;i++){
    pq.push(nums[i]);
    } 
    
    int front=pq.top();
    pq.pop();
    int cnt=1;
    int maxi=1;
    while(!pq.empty()){
    int bck=pq.top();
    pq.pop();

    if((front-bck)==1){
    cnt++;
    maxi=max(maxi,cnt);
    }
    else if(bck==front){
    continue;
    }
    else{
    cnt=1;
    }
    front=bck;
    }
    return maxi;
    }
};