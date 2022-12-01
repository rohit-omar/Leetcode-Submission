class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        vector<int> ind1{-1,1,0,0};
        vector<int> ind2{0,0,1,-1};
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    qu.push({i,j});
                }
            }
        }
        int count=-1;
        while(!qu.empty()){
            int sz = qu.size();
            count ++;
            while(sz--){
                int i = qu.front().first;
                int j = qu.front().second;
                qu.pop();
                for(int k=0;k<4;k++){
                    int x = i + ind1[k];
                    int y = j + ind2[k];
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                        fresh--;
                        grid[x][y]=2;
                        qu.push({x,y});
                    }
                }
            }
        }
        if(fresh!=0) return -1;
        if(count==-1) return 0;
        return count;
    }
};