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
//Reviewed on 03/20/2025
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder;
    }

    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == nullptr) { return; }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};
