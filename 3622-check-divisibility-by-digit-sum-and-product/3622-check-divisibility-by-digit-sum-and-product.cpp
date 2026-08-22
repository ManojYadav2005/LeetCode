class Solution {
public:

    bool digit(int n){
    int sm=0;
    int ngt=n;
    int product=1;
    while(ngt!=0){
    int rem=ngt%10;
    sm=sm+rem;
    product=product*rem;
    ngt=ngt/10;
    }
    int totlsm=product+sm;

    if(n%totlsm==0) return true;
    else  return false;
    }
    bool checkDivisibility(int n) {

    return digit(n);  
    }
};