class Solution {
public:
    int trap(vector<int>& height) {
  
    int n=height.size();
    int lftmx=0,rgtmx=0,total=0;
    int l=0,r=n-1;
    
    while(l<r){
    //1. left process kro   
    if(height[l]<=height[r]){ 
    // Current chhota hai    
    if(lftmx>height[l]){
    total+=lftmx-height[l];  }
    else{
    lftmx=height[l];
    }
    l=l+1;
    }
    //2. right process kro
    else{
    //Current chhota hai
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