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

    void findPath(TreeNode* &root, int &targetSum, int &res, long sum) {
        if(root == nullptr) {
            return;
        }

        sum+=root->val;

        if(targetSum-sum == 0) res++;

        findPath(root->left, targetSum, res, sum);
        findPath(root->right, targetSum, res, sum);
    }

    void pathSum(TreeNode* &root, int &targetSum, int &res) {
        if(root == nullptr) {
            return;
        }

        findPath(root, targetSum, res, 0);

        pathSum(root->left, targetSum, res);
        pathSum(root->right, targetSum, res);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        pathSum(root, targetSum, res);
        return res;
    }

    
};