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
        //brute force with two arrays
        vector<int> tree1, tree2;
        treeLeaves(root1, tree1);
        treeLeaves(root2, tree2);
        int size1 = tree1.size(), size2 = tree2.size();
        if(size1 != size2) return false;
        for(int i = 0; i < size1; i++) {
            if(tree1[i] != tree2[i]) return false;
        }
        return true;
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