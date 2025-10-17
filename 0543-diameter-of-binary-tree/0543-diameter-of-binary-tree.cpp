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
    int depth(TreeNode* root) {
        if(root == nullptr) return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //get len of longest left and longest right using max add them thats diameter
        if(root == nullptr) return 0;

        int throughRoot = depth(root->left) + depth(root->right);

        int leftSubTree = diameterOfBinaryTree(root->left);

        int rightSubTree = diameterOfBinaryTree(root->right);

        return max(throughRoot, max(leftSubTree, rightSubTree));
    }
};