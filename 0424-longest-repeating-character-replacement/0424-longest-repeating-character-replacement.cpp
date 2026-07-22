class Solution {
public:
    int characterReplacement(string s, int k) {

    int n=s.size();

    int l=0;
    int maxfreq=0;
    int mini=INT_MAX;

    unordered_map<char,int>mpp;
    int ans=0;
    for(int r=0;r<n;r++){
    mpp[s[r]]++;

    maxfreq=max(maxfreq,mpp[s[r]]);
    
    while((r-l+1)-maxfreq>k){
    mpp[s[l]]--;
    l++;
    }
    ans=max(ans,r-l+1);
    }
    return ans;       
    }
};


