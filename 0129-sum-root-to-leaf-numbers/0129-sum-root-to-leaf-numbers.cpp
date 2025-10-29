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
    static void dfs(TreeNode* root, int curr, int& sum) {
        if(!root) return;

        curr = curr * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr) { sum += curr; return; }
            
        dfs(root->left, curr, sum);

        dfs(root->right, curr, sum);
    }

    int sumNumbers(TreeNode* root) {
        //dfs pre-order traversal
        //store each path to nullptr as a string
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};