class Solution {
public:
    int divide(int dividend, int divisor) {
      if(dividend==INT_MIN && divisor==-1){
      return INT_MAX;
      }  
      bool negative=(dividend<0)^(divisor<0);

      long long a=llabs((long long)dividend);
      long long b=llabs((long long)divisor);
      
      long long ans = 0;
      
      while(a>=b){
        int shift=0;
        while(a>=(b<<(shift+1))){
        shift++;
        }
        ans=ans+(1LL<<shift);
        a=a-(b<<shift);
      }
        if(negative)
        ans=-ans;

        return (int)ans;
    }
};