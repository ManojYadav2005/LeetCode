// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//      int n=ratings.size();
//      vector<int>candies(n,1);
//     // left to right
//      for(int i=1;i<n;i++){
//      if(ratings[i]>ratings[i-1]){
//      candies[i]=candies[i-1]+1;
//      }
//      } 
//      // right to left
//      for(int i=n-2;i>=0;i--){
//      if(ratings[i]>ratings[i+1]){
//      candies[i]=max(candies[i],candies[i+1]+1);
//      }
//      }  
//      int sm=0;
//      for(int i=0;i<n;i++){
//      sm=sm+candies[i];
//      } 
//      return sm;
//     }
// };










class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     vector<int>candies(n,1);
    
     int sm=1;
     int i=1;
    
    
     while(i<n){
     
     if(ratings[i]==ratings[i-1]){
     sm=sm+1;
     i++;
     continue;
     }

     int peak=1;
     while(i<n && ratings[i]>ratings[i-1]){
     peak++;
     sm=sm+peak;
     i++;
   
     }
     
     int down=1;
     while(i<n && ratings[i]<ratings[i-1]){
     sm+=down;
     down++;
     i++;
     }

    if(down>peak) sm=sm+(down-peak);
    // decreasing slope
    if(peak==0 && down>0) {
    sm++;
    }
     }
     return sm;
    }
};