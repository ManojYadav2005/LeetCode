class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.size();
     int l=0;
     int r=0;
    int mxlen=0;
     vector<int> hash(256, -1);
     while(r<n){
     if(hash[s[r]]!=-1){
     if(hash[s[r]]>=l){
     l=hash[s[r]]+1; }
    
     }
      mxlen=max(mxlen,r-l+1);
      hash[s[r]]=r;
      r++;
     }   
     return mxlen;
    }
};










// class Solution {
// public:

//     bool check(int l,int r,string s){
//     string temp;

//     for(int i=l;i<=r;i++){
//     temp=temp+s[i];
//     }
//     sort(temp.begin(),temp.end());
//     int m=temp.size();

//     for(int i=1;i<m;i++){
//     if(temp[i]==temp[i-1]) return true;
//     }

//     return false;
//     }

//     int lengthOfLongestSubstring(string s) {
//     int n=s.size();
 
//     int mxlen=1;
//     if(s.size() == 0) return 0;
//     for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//     if(check(i,j,s)==false){
//     mxlen=max(mxlen,j-i+1);
//     }
//     else{
//     break;  }
//     }
//     }
//     return mxlen;    
//     }
// };