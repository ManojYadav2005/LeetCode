class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxi=0;
    int n=s.size();
  //  if(n==1) return 1;
    for(int i=0;i<n;i++){
    vector<int>vis(256,0);   
    for(int j=i;j<n;j++){
    if(vis[s[j]]){
    break;
    }
    vis[s[j]]=1;
    maxi=max(maxi,j-i+1);
    }
    } 
    return maxi;    
    }
};