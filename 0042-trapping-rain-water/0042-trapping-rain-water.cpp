class Solution {
public:
    int trap(vector<int>& height) {
     int n=height.size();
     int l=0;
     int r=n-1;
     int sm=0;
     int lftmx=0;
     int rghtmx=0;
     while(l<r){
     // case 1
     if(height[l]<=height[r]){
     if(lftmx>height[l]){
     sm=sm+(lftmx-height[l]);
     }
     else lftmx=height[l];
     l++;
     }
     // case 2
     else{
      if(rghtmx>height[r]){
      sm=sm+(rghtmx-height[r]);
      }
      else rghtmx=height[r];
      r--;
     }
     } 
     return sm;  
    }
};