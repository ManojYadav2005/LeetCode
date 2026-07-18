class Solution {
public:
    int cnt(int n){
    int cont=0;
    while(n>0){
    
    if((n&1)!=0) cont++;
     n=n>>1;

    }
    return cont;
    }

    int hammingWeight(int n) {
    return cnt(n);    
    }
};