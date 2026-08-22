class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
    int n=code.size();
    vector<int> ans(n,0);
    if(k==0){
    return ans;
    }
    if(k<0){
    int xk=abs(k);
    for(int i=0;i<n;i++){
    int sm=0;
    for(int j=1;j<=xk;j++){
    sm=sm+code[(i-j+n)%n];
    }
    ans[i]=sm;
    }
    }
    if(k>0){
    for(int i=0;i<n;i++){
    int sm=0;
    for(int j=1;j<=k;j++){
    sm=sm+code[(i+j)%n];
    }
    ans[i]=sm;
    }
    }
  return ans;
     
    }
};