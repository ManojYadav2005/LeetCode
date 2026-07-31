class Solution {
public:
    int minimumPushes(string word) {
    int n=word.size();


    map<char,int>mpp;
    for(int i=0;i<n;i++){
    mpp[word[i]]++;
    }

    vector<pair<char,int>>v(mpp.begin(),mpp.end());
    sort(v.begin(),v.end(),
    [](pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
    });


    
    int cnt=0;
    for(int i=0;i<mpp.size();i++){
   
    cnt=cnt+((i/8)+1)*v[i].second;
    }
    return cnt;
    }
};