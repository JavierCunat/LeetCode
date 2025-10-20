/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //lowest == closest to p and q nodes
        //if both p and q less than or greater than root only have to explore that
        //if both of them split by root we should return that root
        if(!root) return nullptr;

        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};