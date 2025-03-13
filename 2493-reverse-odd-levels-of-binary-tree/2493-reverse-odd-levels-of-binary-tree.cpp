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
//reviewed on 3/12/2025
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* original = root;
        revOddLevels(root->left, root->right, 1);
        return original;
    }

   void revOddLevels(TreeNode* left, TreeNode* right, int level) {
        if(left == nullptr || right == nullptr) {
            return;
        }

        if(level % 2 == 1) {
            swap(left->val, right->val);
        }

        //pair each subtree node:
//left subtree: left (left->left) child with the right child of right subtree(right->right) //outer with outer
//right subtree: right child of left (left->right) with left child of right //inner with inner
        revOddLevels(left->left, right->right, level + 1);
        revOddLevels(left->right, right->left, level + 1);
   }

};
