class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
     vector<int>arr1;
     vector<int>arr2;
     int n=nums.size();
     int l=0;
     int r=0;
     arr1.push_back(nums[0]);
     arr2.push_back(nums[1]);
     for(int i=2;i<n;i++){
     
     if(arr1[l]>arr2[r]){
     arr1.push_back(nums[i]);
     l++;
     } 
     else{
     arr2.push_back(nums[i]);
     r++;
     } 
     }
     vector<int>merge;
     int n1=arr1.size();
     for(int i=0;i<n1;i++){
     merge.push_back(arr1[i]);
     }  
     
     for(int i=0;i<arr2.size();i++){
     merge.push_back(arr2[i]);
     }   
     return merge;
    }
};