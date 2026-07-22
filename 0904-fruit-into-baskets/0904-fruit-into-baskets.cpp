class Solution {
public:
    int totalFruit(vector<int>& fruits) {

     int n=fruits.size();
     int maxlen=0;
     unordered_map<int,int>hash;
     int l=0;

     for(int r=0;r<n;r++){
     hash[fruits[r]]++;
     while(hash.size()>2){
     hash[fruits[l]]--;  
     if(hash[fruits[l]] == 0) hash.erase(fruits[l]);   
     
     l++;
     }
     maxlen=max(maxlen,r-l+1);
     }
     return maxlen;
    }
};