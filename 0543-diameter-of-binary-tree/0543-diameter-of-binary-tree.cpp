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
    int depth(TreeNode* curr, int& res) {
        if(!curr) return 0;
        int L = depth(curr->left, res);
        int R = depth(curr->right, res);
        res = max(res, L+R);
        return 1 + max(L, R);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //dfs and update best
        int res = 0;
        depth(root, res);
        return res;
    }
};