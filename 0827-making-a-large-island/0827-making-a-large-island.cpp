class Solution {
public:
 vector<int>parent;
 vector<int>rank;
 vector<int>compSize;

 int find(int i, vector<int>&parent){
    if(i == parent[i]) return i;
    return parent[i] = find(parent[i], parent);
 }

 void Union(int x, int y,
            vector<int>&parent,
            vector<int>&rank,
            vector<int>&compSize){

     int x_parent = find(x, parent);
     int y_parent = find(y, parent);

     if(x_parent == y_parent) return;

     if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
        compSize[x_parent] += compSize[y_parent];
     }
     else if(rank[y_parent] > rank[x_parent]){
        parent[x_parent] = y_parent;
        compSize[y_parent] += compSize[x_parent];
     }
     else{
        parent[y_parent] = x_parent;
        rank[x_parent]++;
        compSize[x_parent] += compSize[y_parent];
     }
 }

 int largestIsland(vector<vector<int>>& grid) {

     int n = grid.size();

     parent.resize(n*n);
     rank.resize(n*n, 0);
     compSize.resize(n*n, 1);

     for(int i = 0; i < n*n; i++){
        parent[i] = i;
     }

     int delrow[4] = {-1,0,1,0};
     int delcol[4] = {0,1,0,-1};

     // build DSU
     for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            if(grid[row][col] == 0) continue;

            int node = row*n + col;

            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == 1){

                    int adjNode = nrow*n + ncol;
                    Union(node, adjNode, parent, rank, compSize);
                }
            }
        }
     }

     int ans = 0;

     // try flipping 0
     for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){

            if(grid[row][col] == 1) continue;

            unordered_set<int> st;

            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == 1){

                    int adjNode = nrow*n + ncol;
                    st.insert(find(adjNode, parent));
                }
            }

            int currSize = 1;

            for(auto par : st){
                currSize += compSize[par];
            }

            ans = max(ans, currSize);
        }
     }

     // all 1 case
     for(int i = 0; i < n*n; i++){
        ans = max(ans, compSize[find(i, parent)]);
     }

     return ans;
 }
};