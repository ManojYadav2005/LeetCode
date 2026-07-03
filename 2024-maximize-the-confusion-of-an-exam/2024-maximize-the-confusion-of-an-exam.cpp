class Solution {
public:

    bool check(string &s, int len, int k){

        int n = s.size();

        int tCount = 0;
        int fCount = 0;

        for(int i = 0; i < len; i++){
            if(s[i] == 'T') tCount++;
            else fCount++;
        }

        if(tCount <= k || fCount <= k)
            return true;

        for(int i = len; i < n; i++){

            if(s[i-len] == 'T') tCount--;
            else fCount--;

            if(s[i] == 'T') tCount++;
            else fCount++;

            if(tCount <= k || fCount <= k)
                return true;
        }

        return false;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();

        int lo = 1;
        int hi = n;

        int ans = 1;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(check(answerKey, mid, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};