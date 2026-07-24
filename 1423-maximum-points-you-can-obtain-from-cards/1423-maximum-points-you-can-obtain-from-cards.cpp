class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    
    int lftsm=0;
    for(int i=0;i<k;i++){
    lftsm=lftsm+cardPoints[i];
    } 
    
    int maxi=lftsm;
    int l=0;
    int r=n-1;
    int rghtsm=0;
    for(int i=k-1;i>=0;i--){
    lftsm=lftsm-cardPoints[i];
    rghtsm+=cardPoints[r];
    maxi=max(maxi,(lftsm+rghtsm));
    r--;
    } 
    return maxi; 
    }
};