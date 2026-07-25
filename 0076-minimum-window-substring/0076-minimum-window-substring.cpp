class Solution {
public:
    string minWindow(string s, string t) {
     int n = s.size();
    int l=0;
    int r=0;
    
    int requrcnt=t.size();
    unordered_map<char,int>mpp;
    
    for(char it:t) mpp[it]++;

    int minwindwsiz=INT_MAX;
    int start_i=0;
    while(r<n){

    char ch=s[r];

    if(mpp[ch]>0) requrcnt--;
    mpp[ch]--;

    while(requrcnt==0){
    int curwindsiz=r-l+1;

    if(minwindwsiz>curwindsiz){
    minwindwsiz=curwindsiz;
    start_i=l;
    }
    mpp[s[l]]++;
    if(mpp[s[l]]>0) requrcnt++;
    l++;
    }
    r++;
    }  
    return (minwindwsiz == INT_MAX) ? "" : s.substr(start_i, minwindwsiz);
    }
};