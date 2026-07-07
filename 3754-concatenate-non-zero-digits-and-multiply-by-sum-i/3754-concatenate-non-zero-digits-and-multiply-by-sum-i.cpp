class Solution {
public:
    long long sumAndMultiply(int n) {

     string s="";
     int sm=0;
     while(n>0){
     int rem=n%10;

     string remainder=to_string(rem);

     if(rem!=0){
     s=s+remainder; 
     }
     sm=sm+rem;
     n=n/10;
     } 
     
     reverse(s.begin(),s.end());
     if (s.empty()) return 0;
     long long number=stoll(s);
    long long int res=number*sm;

     return res; 
    }
};