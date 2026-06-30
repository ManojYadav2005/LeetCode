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

    if(x_parent == y_parent) return ;

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

    int removeStones(vector<vector<int>>& stones) {
     
    int n=stones.size();
    int m=stones[0].size();


    rank.resize(n,0);
    parent.resize(n);  

    for(int i=0;i<n;i++){
    parent[i]=i;
     }

    for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){

    if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])){
    Union(i,j,parent,rank); }
    }
    }

    int comp=0;
    for(int i=0;i<parent.size();i++){
    if(find(i,parent) == i){
    comp++;
    }
    }
    return n-comp;
    } 
    
};