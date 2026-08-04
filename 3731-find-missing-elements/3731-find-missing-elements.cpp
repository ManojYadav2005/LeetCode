class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

    priority_queue<int,vector<int>,greater<int>>pq; 
    int n=nums.size();
    for(int i=0;i<n;i++){
    pq.push(nums[i]);
    }
    int prev=pq.top();
    pq.pop();

    vector<int>v;

    while(!pq.empty()){
    int curr=pq.top();
    pq.pop();
    
    if(abs(curr-prev)>1){
    v.push_back(prev+1);
    pq.push(prev+1);
    pq.push(curr);
    }
    else prev=curr;

    }
    return v;
    }
};