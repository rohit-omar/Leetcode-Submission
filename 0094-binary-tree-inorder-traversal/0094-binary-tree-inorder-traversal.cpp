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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode* node =root;
        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                node=curr->right;
            }
        }
        return ans;
    }
};