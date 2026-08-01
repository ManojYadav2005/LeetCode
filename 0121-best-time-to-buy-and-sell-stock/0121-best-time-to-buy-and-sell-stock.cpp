class Solution {
public:
    int maxProfit(vector<int>& prices) {

    int n=prices.size();
    int miniele=INT_MAX;
    int maxprofit=INT_MIN;
    for(int i=0;i<n;i++){
    miniele=min(miniele,prices[i]);
    int profit=prices[i]-miniele;
    maxprofit=max(maxprofit,profit); 
    }  
    return maxprofit;   
    }
};