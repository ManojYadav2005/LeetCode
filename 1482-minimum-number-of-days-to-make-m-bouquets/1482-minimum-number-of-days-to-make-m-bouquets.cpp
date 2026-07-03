class Solution {
public:
    bool check(vector<int>& bloomDay,int mid,int m,int k){
    int cnt=0;
    int kcnt=0;
    int n=bloomDay.size();

    for(int i=0;i<n;i++){
    if(bloomDay[i]<=mid){
    kcnt++;
    }
    else{
    kcnt=0;}
    if(kcnt==k){
    cnt++;
    kcnt=0;}
    }
    
     return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

    int n=bloomDay.size();

    if(1LL * m * k > n) return -1;

    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    maxi=max(maxi,bloomDay[i]);
    }

    int lo=0;
    int hi=maxi;
    int result=-1;

    while(lo<=hi){
    
    int mid=lo+(hi-lo)/2;
    
   
    if(check(bloomDay,mid,m,k)){ // kya mein bna paa rha hu if haan toh phir aur minimum mein bnao
    result=mid;
    hi=mid-1; // minimum dhoonda left mein
    
    }
    else{
        lo=mid+1;
    }
    } 
    return result;   
    }
};