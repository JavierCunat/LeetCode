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

    void dfs(TreeNode* &node, int &val) {
        if(node == nullptr) return;

        if(node->val > val) {
            dfs(node->left, val);
        } else {
            dfs(node->right, val);
        }

        if(node->val > val && node->left == nullptr) {
            node->left = new TreeNode(val);
        
        }

        if(node->val < val && node->right == nullptr) {
            node->right = new TreeNode(val);
        }
        
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;

        if(node == nullptr) return new TreeNode(val);
        //traverse through tree if val is less than current val and node left is null put it there
        dfs(root, val);

        return root;
    }
};