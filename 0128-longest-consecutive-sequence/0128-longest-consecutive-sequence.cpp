class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int>st;
    
    int n=nums.size();

    for(auto it:nums){
    st.insert(it);
    } 
    int maxi=0;
    for(auto x:st){
    
    if(st.find(x-1)==st.end()){ // sequence start
    int cnt=1;
    int cur=x;
    
    while(st.find(cur+1)!=st.end()){
    cnt++;
    cur++;
    }
    maxi=max(maxi,cnt);
    }
    } 
    return maxi;  
    }
};