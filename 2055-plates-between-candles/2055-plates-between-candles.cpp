class Solution {
public:
     int lowerbound(int x,vector<int>&arr){
     int n=arr.size();
     int lo=0,hi=n-1;
     int idx=-1;
     while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(arr[mid]<=x){
        idx=mid;
        lo=mid+1;
        }
        else{
        hi=mid-1;
        }
     }
     return idx;
     }


    int uperbound(int x,vector<int>&arr){
        int n=arr.size();
        int lo=0,hi=n-1;
        int idx=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(arr[mid]<x){
            
            lo=mid+1;
            }
            else{
            idx=mid;
            hi=mid-1;
            }
        }
        return idx;
        }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        

        vector<int> candind;

        int n=s.length();
        for(int i=0;i<n;i++){
        if(s[i]=='|')
        candind.push_back(i);
        }
        int q=queries.size();
        vector<int>ans(q, 0);
        for (int i=0;i<q;i++){

        int ub=uperbound(queries[i][0],candind);
        int lb=lowerbound(queries[i][1],candind);

        if (ub == -1 || lb == -1 || ub >= lb) continue;

        ans[i]=(candind[lb]-candind[ub]-1)-(lb-ub-1);
        }
        return ans;
    }
};