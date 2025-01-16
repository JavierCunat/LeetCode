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
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }

    int maxDepth(TreeNode* root, int depth) {
        if(root == nullptr) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->left, depth), maxDepth(root->right, depth));
        }   
        
    }

};