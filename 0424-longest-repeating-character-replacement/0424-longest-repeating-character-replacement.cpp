class Solution {
public:
    int characterReplacement(string s,int k) {

    vector<int>mpp(26,0);  

    int l=0,r=0,maxf=0,maxlen=0;
    int n=s.size();
    
    while(r<n) {
    mpp[s[r]-'A']++;
    maxf=max(maxf,mpp[s[r]-'A']);

    if(((r-l+1) - maxf) > k){
    mpp[s[l]-'A']--;
    maxf=0;
    l++;
    }
    if(((r-l+1) -maxf) <= k){
    maxlen=max(maxlen,r-l+1);
    }
    r++;
     }  
     return maxlen;
    }
};