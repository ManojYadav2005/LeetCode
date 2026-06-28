class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    int MOD=1e9+7;
    vector<vector<pair<int,int>>>adj(n);
   
    for(auto it:roads){
    int u=it[0];
    int v=it[1];
    int wt=it[2];

    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
    }
    vector<long long>dist(n,LLONG_MAX);
    vector<long long>pathcnt(n,0);

    dist[0]=0;
    pathcnt[0]=1;

    priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
    >pq;

    pq.push({0,0});

    while(!pq.empty()){
    auto it=pq.top();
     pq.pop();
     
    long long int dis=it.first;
    int node=it.second;
   
    
    if(dis>dist[node]) continue;

    for(auto it:adj[node]){
    int adjnod=it.first;
    int wt=it.second;
     
    if(dis+wt<dist[adjnod]){
    dist[adjnod]=dis+wt;
    pq.push({dis+wt,adjnod});
    pathcnt[adjnod]=pathcnt[node];
    }
    else if( wt+dis==dist[adjnod]){
    pathcnt[adjnod]=(pathcnt[adjnod]+pathcnt[node])%MOD; 
    }
    }

    }  
    return pathcnt[n-1];  
    }
};