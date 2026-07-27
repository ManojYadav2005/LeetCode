// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//     int n=nums.size();
//     int maxi=INT_MIN;    
//     for(int i=0;i<n;i++){
//      int pro=nums[i]-1;   
//     for(int j=i+1;j<n;j++){
//     maxi=max(maxi,(pro)*(nums[j]-1));
//     }
//     }
//     return maxi;
//     }
// };



class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
    priority_queue<int> pq;
    for(int x: nums) {
    pq.push(x);
    }
    int first=pq.top();
    pq.pop();

    int second=pq.top();
    pq.pop();

    return (first-1)*(second-1);
    }
};