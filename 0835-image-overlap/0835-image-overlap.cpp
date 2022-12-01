class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = img2.size();
        vector<pair<int,int>> image1,image2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1) image1.push_back({i,j});
                if(img2[i][j]==1) image2.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int> hash;
        for(auto [i1,j1]:image1){
            for(auto [i2,j2]:image2){
                hash[{i2-i1,j2-j1}]++;
                ans=max(ans,hash[{i2-i1,j2-j1}]);
            }
        }
        return ans;
    }
};