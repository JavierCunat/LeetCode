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
//reviewed on 8/4/2025
public:
    bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    
    int leftDepth = maximumDepth(root->left);
    int rightDepth = maximumDepth(root->right);
    if (abs(leftDepth - rightDepth) > 1) return false;
    
    return isBalanced(root->left) && isBalanced(root->right);
}

    int maximumDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    
    return 1 + std::max(maximumDepth(root->left), maximumDepth(root->right));
}
};
