class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                dfs(adj,it,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i!=j) adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                ans++;
                dfs(adj,i,vis);
            }
        }
        return ans;
    }
};