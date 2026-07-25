class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>>pq;
    
    unordered_map<int,int>mpp;

    for(int i=0;i<nums.size();i++){
    mpp[nums[i]]++;
    }
    for(auto it: mpp){
    pq.push({it.second , it.first});
    }  
    vector<int>v;
    while(k>0){
    auto it=pq.top();
    
    pq.pop();
    v.push_back(it.second);
    k--;
    } 
    return v;
    }
};