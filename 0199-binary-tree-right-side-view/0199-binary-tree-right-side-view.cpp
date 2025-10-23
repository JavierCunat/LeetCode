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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            stack<TreeNode*> stack;
            for(int i = 0; i < s; i++) {
                TreeNode* cur = q.front(); q.pop();
                if(!cur) continue;
                stack.push(cur);
                q.push(cur->left);
                q.push(cur->right);
            }
            if(!stack.empty()) res.push_back((stack.top())->val);
        }

        return res;
    }
};