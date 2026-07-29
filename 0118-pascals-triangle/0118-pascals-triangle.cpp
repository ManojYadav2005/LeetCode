class Solution {
public:
    
vector<int> solve(int n){
    long long int ans=1;    
    vector<int>ansrow;
    ansrow.push_back(1);
    

    for(int col=1;col<n;col++){
    ans=ans*(n-col);
    ans=ans/(col);
    ansrow.push_back(ans);
    }
    return ansrow;
    }


    vector<vector<int>> generate(int numRows) {
    vector<vector<int>>result;

    for(int i=1;i<=numRows;i++){
  
    result.push_back(solve(i));
    }  
    return result; 
    }
};