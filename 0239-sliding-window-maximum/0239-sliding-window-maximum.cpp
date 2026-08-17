class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    deque<int>dq;
    int n=nums.size();
    for(int i=0;i<n;i++){
    
    if(!dq.empty() && dq.front()<=i-k){ // Deque ka front index current sliding window ke bahar chala gaya hai kya?
    dq.pop_front();
    }
    
    while(!dq.empty() && nums[dq.back()]<=nums[i]){
    dq.pop_back();
    }
    dq.push_back(i);

    if(i>=k-1){// Kya current window mein ab k elements aa chuke hain
    ans.push_back(nums[dq.front()]);
    }
    } 
    return ans;
    }
};