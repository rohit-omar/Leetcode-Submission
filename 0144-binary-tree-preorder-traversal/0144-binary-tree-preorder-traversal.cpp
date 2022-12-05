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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(!root) return pre;
        stack<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* node = qu.top();
            qu.pop();
            pre.push_back(node->val);
            if(node->right) qu.push(node->right);
            if(node->left) qu.push(node->left);
        }
        return pre;
    }
};