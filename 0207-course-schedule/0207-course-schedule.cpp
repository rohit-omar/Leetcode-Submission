class Solution {
public:
    
    // OPT IS TAKEN FOR OPTIMIZATION
    // IT WAS GIVING TLE DUE TO NORMAL OPERATION
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis,vector<int>& opt){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                if(!dfs(adj,it,vis,opt)) return false;
                else opt[it]=2;
            }else if(vis[it]==1 && opt[it]!=2){
            return false;
            }
        }
        opt[node]=2;
        return true;
    }
    bool canFinish(int num, vector<vector<int>>& pr) {
        int n = pr.size();
        vector<vector<int>> adj(num);
        for(int i=0;i<n;i++){
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        vector<int> vis(num,0),opt(num,-1);
        for(int i=0;i<num;i++){
            if(vis[i]==0){
                if(!dfs(adj,i,vis,opt)) return false;
            }
        }
        return true;
    }
};