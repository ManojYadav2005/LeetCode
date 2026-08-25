class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> v;
    int n=intervals.size();
    for(int i=0;i<n;i++){
    v.push_back({intervals[i][0],intervals[i][1]});
    }
    v.push_back({newInterval[0],newInterval[1]});
    
    sort(v.begin(),v.end());

    vector<vector<int>> ans;
    for(int i=0;i<v.size();i++){
    if(ans.empty()){
    ans.push_back({v[i][0],v[i][1]});
    }
    if(v[i][0]<=ans.back()[1]){
    ans.back()[1]=max(ans.back()[1],v[i][1]);
    }
    else if(v[i][0]>ans.back()[1]){
    ans.push_back({v[i][0],v[i][1]});
    }
    }
    return ans;
    }
};