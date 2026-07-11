class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

     

      vector<vector<int>>adj(n);
      for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }  

      int ans=0;
      vector<int>vis(n,0);
      for(int i=0;i<n;i++){
      
      if(vis[i]) continue;

      queue<int>q;
      q.push(i);
      vis[i]=1;
      int nodes=0;
      int edgs=0;

      while(!q.empty()){
      int node=q.front();
      q.pop();
      nodes++;
      
      edgs+=adj[node].size();
      
      for(auto it:adj[node]){
       if(!vis[it]){
        q.push(it);
        vis[it]=1;
      }
      }
      }
      edgs=edgs/2;
      if(edgs==nodes*(nodes-1)/2) ans++;
      }
      return ans;
    }
};