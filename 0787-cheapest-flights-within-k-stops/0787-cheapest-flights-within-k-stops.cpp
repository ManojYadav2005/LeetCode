class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

      vector<vector<pair<int,int>>> adj(n);
      vector<int>dist(n,1e9);
      for(auto it:flights){
      int u=it[0];
      int v=it[1];
      int wt=it[2];
      adj[u].push_back({v,wt});
      }  

      queue<pair<int,pair<int,int>>>q;

      q.push({0,{src,0}});
     
     
     dist[src]=0;
      while(!q.empty()){
       auto it=q.front();
       q.pop();

       int stops=it.first;
       int node=it.second.first;
       int dis=it.second.second;
       
       if(stops>k) continue;

       for(auto it: adj[node]){
        int adjnod=it.first;
        int wt=it.second;
      
       if(dis+wt<dist[adjnod] && stops<=k){
       dist[adjnod]=dis+wt;
       q.push({stops+1,{adjnod,wt+dis}});
       }
       }
      }

       return dist[dst]==1e9?-1:dist[dst];
    }

};