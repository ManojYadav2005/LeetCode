class Solution {
public:

    vector<int>rank;
    vector<int>parent;

    int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i],parent);
    }
    
    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
    
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);
    
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    
    int n=edges.size();

    parent.resize(n+1);
    rank.resize(n,0);

    

    for(int i=0;i<n;i++){
    parent[i]=i;
    }   
    vector<int>v;

    for(auto it:edges){
    
    if(find(it[0],parent)==find(it[1],parent)){
    return {it[0],it[1]};
    }

    if(find(it[0],parent)!=find(it[1],parent)){
    Union(it[0],it[1],parent,rank);

    }
    }
    return {};
    }
};