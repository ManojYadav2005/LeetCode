class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        >pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!pq.empty()){

        auto it=pq.top();
        pq.pop();
        int diffpath=it.first;
        int row=it.second.first;
        int col=it.second.second;

        for(int i=0;i<4;i++) {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){

        int curdiff=abs(heights[row][col]-heights[nrow][ncol]);
        curdiff=max(diffpath,curdiff);

        if(curdiff<dist[nrow][ncol]){
        dist[nrow][ncol]=curdiff;
        pq.push({curdiff,{nrow,ncol}}); }
        }
        }
        }
        return dist[n-1][m-1];
    }
};