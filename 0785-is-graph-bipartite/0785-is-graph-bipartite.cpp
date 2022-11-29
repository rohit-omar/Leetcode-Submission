class Solution {
public:
    bool isBipartite(vector<vector<int>>& gph) {
        int n= gph.size();
        vector<int> vis(n,0);
        queue<int> qu;
        for(int i=0;i<n;i++){
            if(vis[i]!=0) continue;
            qu.push(i);
            vis[i]=1;
            while(!qu.empty()){
                int tp = qu.front();
                qu.pop();
                for(auto it:gph[tp]){
                    if(vis[it]==0){
                        vis[it]=-vis[tp];
                        qu.push(it);
                    }else if(vis[tp]==vis[it]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};