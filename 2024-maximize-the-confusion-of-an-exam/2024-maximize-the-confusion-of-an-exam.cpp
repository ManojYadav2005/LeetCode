class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
    int n=answerKey.size();

    int l=0;
    int maxlen=0;
    int mini=INT_MAX;
    unordered_map<char,int>mpp;
    for(int r=0;r<n;r++){
    mpp[answerKey[r]]++;
    mini = min(mpp['T'], mpp['F']);
    
    while(mini>k){
    mpp[answerKey[l]]--;
    l++;
    mini=min(mpp['T'],mpp['F']);
    }
    maxlen=max(maxlen,r-l+1);
    }
    return maxlen;    
    }
};