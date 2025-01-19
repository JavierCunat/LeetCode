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
        //optimized to only need two params
       return goodNodes(root, root->val);
    }

    int goodNodes(TreeNode* root, int prev) {
        if (!root) return 0;
        int count= 0;
        if(root->val >= prev) {
            count = 1;
        } 
        count+= goodNodes(root->left, max(prev, root->val));
        count+= goodNodes(root->right, max(prev, root->val));
        return count;
    }
};