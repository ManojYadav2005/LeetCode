class Solution {
public:
     int canmakebouque(int day,vector<int>&bloomDay,int m,int k,int n){
     
     int cnt=0;
     int bqts=0;
     for(int i=0;i<n;i++){

     if(bloomDay[i]<=day){
     cnt++;
     if(cnt==k){
     bqts++;
     cnt=0;}
    
     }
     else{
      cnt=0;
     }
     }
     return bqts;
     }
    
    int minDays(vector<int>& bloomDay,int m,int k){
     
     int lo=*min_element(bloomDay.begin(),bloomDay.end());
     int hi=*max_element(bloomDay.begin(),bloomDay.end());
     int n=bloomDay.size();
     
     int ans=-1;
     while(lo<=hi){
     int mid=lo+(hi-lo)/2;

     if(canmakebouque(mid,bloomDay,m,k,n)>=m){
        ans=mid;
        hi=mid-1;
     }
     else{
        lo=mid+1;
     }
     }  
     return ans;
    }
};