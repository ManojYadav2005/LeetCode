class Solution {
public:
    int check(int n,vector<int>& quantities,int mid){
    int sm=0;

    for(int i=0;i<quantities.size();i++){
    sm +=(quantities[i]+mid-1)/ mid;
    }
    return sm;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

     int lo=1;
     int hi=*max_element(quantities.begin(),quantities.end());
     int res=0;
     while(lo<=hi){
     int mid=lo+(hi-lo)/2;

     int find=check(n,quantities,mid);

     if(find<=n){
        hi=mid-1;
        res=mid;
     }
     else{
        lo=mid+1;
     }
     }
     return res;   
    }
};