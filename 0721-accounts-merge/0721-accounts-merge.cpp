class Solution {
public:
     vector<int>parent;
     vector<int>rank;

     int find(int i,vector<int>&parent){
     if(i==parent[i]) return i;
     return parent[i]=find(parent[i],parent);

     }

     void Union(int x,int y,vector<int>&parent,vector<int>&rank){
      int x_parent=find(x,parent);
      int y_parent=find(y,parent);

      if(x_parent == y_parent) return;

      if(rank[x_parent]>rank[y_parent]){
      parent[y_parent]=x_parent;
      }
     else if(rank[x_parent]<rank[y_parent]){
      parent[x_parent]=y_parent;
      }
      else{
      parent[y_parent]=x_parent;
      rank[x_parent]++;
      }
     }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      
      int n=accounts.size();
      rank.resize(n,0);
      parent.resize(n);

      for(int i=0;i<n;i++){
      parent[i]=i; }

      // Build DSU 
      unordered_map<string,int>mpp;
      for(int i=0;i<n;i++){
        
      for(int j=1;j<accounts[i].size();j++){
      string mail=accounts[i][j];
      if(mpp.find(mail)==mpp.end()){
      mpp[mail]=i;
      }  
      else{
        Union(i,mpp[mail],parent,rank); }
      }
      }
      // parent -> emails
      vector<vector<string>>mergemail(n);

      for(auto &it:mpp){
        string mail=it.first;
        int node=it.second;

        int root=find(node,parent);
        mergemail[root].push_back(mail);
      }


      vector<vector<string>> ans;

      for(int i=0;i<n;i++){

        if(mergemail[i].empty()) continue;
        sort(mergemail[i].begin(), mergemail[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto &mail : mergemail[i]){
        temp.push_back(mail);
        }
        ans.push_back(temp);
    }
    return ans;
    }
};