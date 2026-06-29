class Solution {
public:
     
     vector<int>parent;
     vector<int>rank;

     int find(int i,vector<int>&parent){
     if(parent[i]==i) return i;
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
        parent[x_parent]=y_parent;
        rank[y_parent]++;
     }
     }

    bool equationsPossible(vector<string>& equations) {
      parent.resize(26);
      rank.resize(26,0);

      for(int i=0;i<26;i++){
      parent[i]=i;
      }  

      for(string &s:equations){
      if(s[1] =='='){
      Union(s[0]-'a',s[3]-'a',parent,rank);
      }
      }
       for(string &s:equations){
        if(s[1] =='!'){
        char first=s[0];  // a
        char second=s[3]; //b

        int parent_first=find(first-'a',parent);
        int parent_second=find(second-'a',parent);

        if(parent_first == parent_second){
        return false;
        }
        }
      }
      return true;
    }
};