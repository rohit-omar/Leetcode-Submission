class Solution {
public:
    bool dfs(int node,vector<vector<int>>& gph, vector<int>& vis){
        for(auto it:gph[node]){
            if(vis[it]==0){
                vis[it]=1-vis[node];
                if(!dfs(it,gph,vis)){
                    return false;
                }
            }else if(vis[it]==vis[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();
        vector<int> vis(n,0);
        vector<int> val(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=0;
                if(!dfs(i,gph,vis)){
                    return false;
                }
            }
        }
        return true;
    }
};