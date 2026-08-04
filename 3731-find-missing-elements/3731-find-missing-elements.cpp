class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

    int mn=INT_MAX;
    int mx=INT_MIN;

    unordered_set<int>st;

    for(int x:nums){
    mn=min(mn,x);
    mx=max(mx,x);
    st.insert(x);
    }
    vector<int>ans;
   for(int i=mn;i<=mx;i++){
    if(st.find(i)==st.end()){
    ans.push_back(i);
    }
    }
    return ans;    
    }
};