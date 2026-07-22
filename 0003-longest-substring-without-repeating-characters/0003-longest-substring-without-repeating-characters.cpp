class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.size();

      vector<int>hash(256,-1);
      int l=0;
      int r=0;
      int mxlen=0;
      while(r<n){
      if(hash[s[r]]!=-1){
      if(hash[s[r]]>=l){
      l=hash[s[r]]+1;
      }
      }
      mxlen=max(mxlen,r-l+1);
      hash[s[r]]=r;
      r++;
    
      }  
      return mxlen;
    }
};