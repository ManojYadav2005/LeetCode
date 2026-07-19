class Solution {
public:
    int countTriplets(vector<int>& arr) {
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
    int xra=0;
    for(int j=i+1;j<n;j++){
    xra=xra^arr[j-1];
    int xrb=0;
    for(int k=j;k<n;k++){
    xrb^=arr[k];

    if(xra==xrb) cnt++;
    }
    }
    } 
    return cnt;   
    }
};