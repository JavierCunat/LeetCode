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
    int goodNodes(TreeNode* root) {
        int goodCount = 0;
        if(root != nullptr) {
            goodNodes(root, root->val, goodCount);
        }
        return goodCount;
    }

    void goodNodes(TreeNode* root, int prev, int& goodCount) {
        if(root != nullptr) {
            if(root->val >= prev) {
                goodCount++;
            }
            goodNodes(root->left, max(prev, root->val), goodCount);
            goodNodes(root->right, max(prev, root->val), goodCount);
        }
    }
};