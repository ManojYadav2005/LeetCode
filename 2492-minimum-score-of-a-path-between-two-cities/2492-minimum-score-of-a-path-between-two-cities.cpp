class Solution {
public:
    
    
    int minScore(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>vis(n+1,0);

    for(auto it:roads){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    } 
   queue<pair<int,int>>q;
   q.push({1,0});
   vis[1]=1;


   int mini=INT_MAX;
   
   while(!q.empty()){
    auto it=q.front();
    q.pop();
    int node=it.first;
    int wt=it.second;

    for(auto p:adj[node]){
    int adjnod=p.first;
    int nwt=p.second; 
     mini=min(mini,nwt);  
    if(!vis[adjnod]){
     
    q.push({adjnod,nwt});
    vis[adjnod]=1;
    
    }
    }
   }
    return mini;
    }
};