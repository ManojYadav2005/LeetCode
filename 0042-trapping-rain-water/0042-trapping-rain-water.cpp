class Solution {
public:
    int trap(vector<int>& height) {
  
    int n=height.size();
    int lftmx=0,rgtmx=0,total=0;
    int l=0,r=n-1;
    while(l<r){
    if(height[l]<=height[r]){  
    if(lftmx>height[l]){
    total+=lftmx-height[l];  }
    else{
    lftmx=height[l];
     }
     l=l+1;
    }
    else{
      if(rgtmx>height[r]){
    total+=rgtmx-height[r];  }
    else{
    rgtmx=height[r];
     } 
     r=r-1;  
    }
    }
    
    return total;
    }
};