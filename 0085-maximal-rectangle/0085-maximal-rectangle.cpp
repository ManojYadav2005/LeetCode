// class Solution {
// public:
//      int larghist(vector<int>&prefixsm){
//      int n1=prefixsm.size();

//      stack<int>st;
//       int maxi=0;
//      for(int i=0;i<=n1;i++){
//      while(!st.empty() && (i==n1 || prefixsm[st.top()]>=prefixsm[i])){
//      int element=prefixsm[st.top()];
//      st.pop();

//      int nse=i;
//      int pse;

//      if(st.empty()){
//      pse=-1;
//      }
//      else{
//         pse=st.top();  }

//      int width=nse-pse-1;
//      int area=element*width;
//      maxi=max(maxi,area);

//      }
     
//      if(i!=n1){
//         st.push(i);}

//      } 
//      return maxi;
//      }


//     int maximalRectangle(vector<vector<char>>& matrix) {
//      int n=matrix.size();
//      int m=matrix[0].size();
//      vector<vector<int>> prefixsm(n,vector<int>(m,0));
//       if(matrix.empty()) return 0;
//      for(int j=0;j<m;j++){// colm
//       int sm=0;  
//      for(int i=0;i<n;i++){//row
//       sm=sm+(matrix[i][j]-'0');
//       prefixsm[i][j]=sm;

//       if(matrix[i][j]=='0'){
//       prefixsm[i][j]=0;
//       sm=0; 
//       }
//      }
//      } 
//       int maxi=0;
//      for(int i=0;i<n;i++){
//      maxi=max(maxi,larghist(prefixsm[i]));
//      }

//      return maxi;  
//     }
// };
















class Solution {
public:
    

    int larghist(vector<int>&heights){
    int n=heights.size();
    
    stack<int>st;
    int maxi=0;

    for(int i=0;i<=n;i++){
    while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
    int ele=heights[st.top()];
    st.pop();

    int nse=i;
    int pse;
    if(st.empty())  pse=-1;
    else pse=st.top();
    
    int width=nse-pse-1;
    int area=ele*width;
    maxi=max(maxi,area);
    }
    st.push(i);
    }
    return maxi;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
     int n=matrix.size();
     int m=matrix[0].size();
     vector<vector<int>>prefsm(n,vector<int>(m,0));
     if(matrix.empty()) return 0;
     
     for(int j=0;j<m;j++){
     int sm=0;
     for(int i=0;i<n;i++){
     sm=sm+(matrix[i][j]-'0');
     prefsm[i][j]=sm;

     if(matrix[i][j]=='0'){
     prefsm[i][j]=0;
     sm=0;}
     }
     }

     int maxi=INT_MIN;

     for(int i=0;i<n;i++){
     maxi=max(maxi,larghist(prefsm[i]));
     }
     return maxi;
    }
};