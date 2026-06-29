class Solution {
public:
 typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
     int n=points.size();
     vector<vector<P>>adj(n);   
// make a graph possible from all nodes;
     for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
     int x1=points[i][0];
     int y1=points[i][1];

     int x2=points[j][0];
     int y2=points[j][1];

     int dist=abs(x2-x1) + abs(y2-y1);

     adj[i].push_back({j,dist});
     adj[j].push_back({i,dist});
     }
     }

     vector<bool>vis(n,false);
     priority_queue<P,vector<P>,greater<P>>pq;

     pq.push({0,0});
     int sum=0;

     while(!pq.empty()){
     auto it=pq.top();
     int node=it.second;
     int sm=it.first;
     pq.pop();
     if(vis[node]==true) continue;

     sum=sum+sm;
     vis[node]=true;
     
     for(auto ngbr:adj[node]){
     int adjnode=ngbr.first;
     int wt=ngbr.second;

     if(!vis[adjnode]){
     pq.push({wt,adjnode});
     }
     }

     }
     return sum;
    }
};