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

    void dfsZigZag(TreeNode* root, bool isLeft, int length, int& maxLength) {
        if(root == nullptr) return;

        maxLength = max(length, maxLength);

        if(isLeft) {
            dfsZigZag(root->right, false, length + 1, maxLength);
            //once this runs out of stack frames of doing zigzag it will come back to this line so we want 
            //to reset and do go down the tree to the next node
            dfsZigZag(root->left, true, 1, maxLength);
        } else { 
            dfsZigZag(root->left, true, length + 1, maxLength);
            dfsZigZag(root->right, false, 1, maxLength);
        }
        
    }


    int longestZigZag(TreeNode* root) {
        //perform dfs to go through each node in the tree
        //at each node do a dfs but following the zig-zag pattern for both directions
        int maxLength = 0;
        dfsZigZag(root->left, true, 1, maxLength);
        dfsZigZag(root->right, false, 1, maxLength);
        return maxLength;
    }

    
};