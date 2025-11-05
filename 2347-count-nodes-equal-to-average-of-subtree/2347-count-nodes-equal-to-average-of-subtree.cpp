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

    static pair<int,int> dfs(TreeNode* root, int& res) {
       if(!root) return {0, 0};

       auto [lSum, lCnt] = dfs(root->left, res);
       auto [rSum, rCnt] = dfs(root->right, res);

       int sum = lSum + rSum + root->val;
       int cnt = lCnt + rCnt + 1;

       if(sum / cnt == root->val) res++;

       return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        //do dfs once and get the subtrees sum
        int res = 0;
        dfs(root, res);
        return res;
    }
};