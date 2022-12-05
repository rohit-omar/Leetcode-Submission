/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int k=diameter(root);
        return height;
    }
private:
    int diameter(TreeNode* root){
        if(root==NULL) return 0;
        int lh=diameter(root->left);
        int rh=diameter(root->right);
        height=max(height,lh+rh);
        return max(lh,rh)+1;
    }
};