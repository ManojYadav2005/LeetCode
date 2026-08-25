class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    vector<vector<int>>merged;
    sort(intervals.begin(), intervals.end());

    for(int i=0;i<n;i++){
    if(merged.empty()){
    merged.push_back({intervals[i][0],intervals[i][1]});
    }
    if(merged.back()[1]>=intervals[i][0]){
    merged.back()[1]=max({merged.back()[1],intervals[i][1]});
    }
    else if(merged.back()[1]<intervals[i][0]){
    merged.push_back({intervals[i][0],intervals[i][1]});
    }
    }
    return merged;
    }
};