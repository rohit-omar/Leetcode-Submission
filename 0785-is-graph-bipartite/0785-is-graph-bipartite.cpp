class Solution {
public:
    bool dfs(int node,vector<vector<int>>& gph, vector<int>& vis, vector<int>& val,int v){
        int t;
        if(v==1){
            t=0;
        }else if(v==0) t=1;
        for(auto it:gph[node]){
            if(vis[it]==0){
                vis[it]=1;
                val[it]=v;
                if(!dfs(it,gph,vis,val,t)){
                    return false;
                }
            }else if(val[it]==t){
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
                if(!dfs(i,gph,vis,val,1)){
                    return false;
                }
            }
        }
        return true;
    }
};