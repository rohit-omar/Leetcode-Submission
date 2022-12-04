class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left=0, right=m-1, top=0, down=n-1;
        vector<int> ans;
        int pro=n*m;
        while(top<=down && left<=right){
            if(!pro) break;
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
                pro--;
            }
            top++;
            if(!pro) break;
            for(int i=top;i<=down;i++){
                ans.push_back(mat[i][right]);
                pro--;
            }
            right--;
            if(!pro) break;
            for(int i=right;i>=left;i--){
                ans.push_back(mat[down][i]);
                pro--;
            }
            down--;
            if(!pro) break;
            for(int i=down;i>=top;i--){
                ans.push_back(mat[i][left]);
                pro--;
            }
            left++; 
        }
        return ans;
    }
};