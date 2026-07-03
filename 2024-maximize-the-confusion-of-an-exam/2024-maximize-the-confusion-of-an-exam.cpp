class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
      int n=answerKey.size();

      int cntf=0;
      int i=0;
      int j=0;
      int maxi=INT_MIN;
      while(j<n){
      
      // case 1 -F maankr chlee pehle

      if(answerKey[j]=='F'){
        cntf++;
      }

      while(cntf>k){
      
      if(answerKey[i]=='F'){
      cntf--;
      }
      i++;
      }
      maxi=max(maxi,j-i+1);
      j++;
      } 


      int cntt=0;
       i=0;
       j=0;

      while(j<n){
      
      // case 1 -F maankr chlee pehle

      if(answerKey[j]=='T'){
        cntt++;
      }

      while(cntt>k){
      
      if(answerKey[i]=='T'){
      cntt--;
      }
      i++;
      }
      maxi=max(maxi,j-i+1);
      j++;
      }  
      
      return maxi;
    }
};