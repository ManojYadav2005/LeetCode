class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    int five=0;
    int ten=0;
    int twnty=0;

    int n=bills.size();

    for(int i=0;i<n;i++){
    if(bills[i]==5) five++;
    if(bills[i]==10){
    
    if(five>=1) five--;
    else return false;
 
    ten++;
    }
    if(bills[i]==20){

    if(ten>=1 && five>=1){
    ten--;
    five--;
    }
    else if(five>=3) five-=3;
    else return false;
    
    twnty++;
    }


    } 
    return true;    
    }
};