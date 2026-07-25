class Solution {
public:
    int maxProduct(int n) {
    
    long long int pro;
    vector<int>v;
    while(n>0){
    long long int rem=n%10;
    v.push_back(rem);
    n=n/10;
    } 
    sort(v.begin(),v.end());
    int m=v.size();
    pro=v[m-1]*v[m-2];
    return pro;   
    }
};