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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //apparently with arrays like this is the best approach O(n+m) n size of tree 1 m size of tree 2 beats 100%
        vector<int> tree1, tree2;
        treeLeaves(root1, tree1);
        treeLeaves(root2, tree2);

        return tree1 == tree2;        
    }

    void treeLeaves(TreeNode* root, vector<int>& seq) {

        if(root != nullptr) {
            if(root->left == nullptr && root->right == nullptr) {
                seq.push_back(root->val);
            }   

            treeLeaves(root->left, seq);
            treeLeaves(root->right, seq);
        }

    }

};