class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      
      vector<vector<pair<int,int>>> adj(n);

      for(auto it:roads){
      int u=it[0];
      int v=it[1];
      int wt=it[2];

      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
      }

       int mod=1e9+7;

       priority_queue<
       pair<long long,int>,
       vector<pair<long long,int>>,
       greater<pair<long long,int>>
        >pq;

     pq.push({0, 0});

     vector<long long>dist(n,1e18);
     vector<long long> ways(n,0);
     
     ways[0]=1;
     dist[0]=0;

     while(!pq.empty()){
     auto it=pq.top();
     long long int dis=it.first;
     int node=it.second;
     pq.pop();

     for(auto ngbr:adj[node]){
     auto adjnod=ngbr.first;
     int wt=ngbr.second;

     if(wt+dis<dist[adjnod]){
     dist[adjnod]=wt+dis;
     ways[adjnod]=ways[node];
     pq.push({dist[adjnod],adjnod});
     }
     else if(dis+wt==dist[adjnod]){
     ways[adjnod]=(ways[adjnod]+ways[node])%mod;
     }
     }
     }
     return ways[n-1];
    }
};