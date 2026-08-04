class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    int m=image.size();
    int n=image[0].size(); 
    int orignl=image[sr][sc];
    queue<pair<int,int>>q;
    vector<vector<int>> vis(m,vector<int>(n,0)); 
    q.push({sr,sc});
    image[sr][sc]=color;
    vis[sr][sc]=1;

    if (orignl == color)
    return image;

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    

    while(!q.empty()){

    auto it=q.front();
    int row=it.first;
    int col=it.second;
    q.pop();

    for(int i=0;i<4;i++){
    int nrow=delrow[i]+row;
    int ncol=delcol[i]+col;

    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==orignl){
    image[nrow][ncol]=color;
    vis[nrow][ncol]=1;
    q.push({nrow,ncol});}
    } 
    }

    return image; 
    }
};