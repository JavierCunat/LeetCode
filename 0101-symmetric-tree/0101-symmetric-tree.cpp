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
    static void invert(TreeNode* root) {
        if(!root) return;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invert(root->left);
        invert(root->right);
    }

    static bool isSame(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;

        if(left == nullptr || right == nullptr || left->val != right->val) return false;

        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        //invert tree and then check if the tree is the same
        invert(root);
        return isSame(root->left, root->right);
    }
};