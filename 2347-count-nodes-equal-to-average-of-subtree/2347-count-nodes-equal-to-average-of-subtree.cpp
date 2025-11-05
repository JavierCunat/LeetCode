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

    static int dfs(TreeNode* root, int& sum, int& count) {
        if (!root) { sum = 0; count = 0; return 0; }

        int lSum = 0, lCnt = 0;
        int rSum = 0, rCnt = 0;

        dfs(root->left, lSum, lCnt);
        dfs(root->right, rSum, rCnt);

        sum = lSum + rSum + root->val;
        count = lCnt + rCnt + 1;

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        //do dfs on each subtree root and return the average, if that node root has same average sum increase res+1
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();

            for(int i = 0; i < s; i++) {
                TreeNode* curr = q.front(); q.pop();
                int count = 0, sum = 0;
                dfs(curr, sum, count);

                if( (sum / count) == curr->val) res++;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return res;
    }
};