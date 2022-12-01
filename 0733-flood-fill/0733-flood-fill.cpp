class Solution {
public:
    void dfs(vector<vector<int>>& img, int color, int ic, int i, int j, int n, int m){
        if(i >=n || j>=m || i<0 || j<0 || img[i][j]!=ic) return;
        img[i][j]=color;
        dfs(img,color,ic,i+1,j,n,m);
        dfs(img,color,ic,i-1,j,n,m);
        dfs(img,color,ic,i,j+1,n,m);
        dfs(img,color,ic,i,j-1,n,m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int ic = img[sr][sc];
        if(ic != color)dfs(img,color,ic,sr,sc, img.size(), img[0].size());
        return img;
    }
};