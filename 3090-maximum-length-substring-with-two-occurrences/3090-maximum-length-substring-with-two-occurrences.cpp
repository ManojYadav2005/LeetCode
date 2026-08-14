class Solution {
public:
    int maximumLengthSubstring(string s) {
    map<char,int>mpp;
    int n=s.size();
    int i=0;
    int mxlen=0;
    for(int j=0;j<s.size();j++) {
    mpp[s[j]]++;

    while(mpp[s[j]]>2){
    mpp[s[i]]--;
    i++;
    }
    mxlen=max(mxlen,j-i+1);
    }  
    return mxlen;   
    }
};