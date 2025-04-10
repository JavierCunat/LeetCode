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
//Reviewed on 4/9/2025
    vector<vector<int>> levelOrder(TreeNode* root) {
        //can do both recursively or iteratively with a q
        vector<vector<int>> res;
        int level = 0;
        queue<TreeNode*> q;
        if(root == nullptr) return res;

        q.push(root);

        while(!q.empty()) {
            int length = q.size();
            res.push_back({});

            for(int i = 0; i < length; i++) {
                TreeNode* node = q.front();
                q.pop();

                res[level].push_back(node->val);
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            level++;
        }
        return res;
    }

    // void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
    //     if(root == nullptr) return;
    //     if(res.size() <= level){
    //         res.push_back({});
    //     }
    //     res[level].push_back(root->val);
    //     levelOrder(root->left, level + 1, res);
    //     levelOrder(root->right, level + 1, res);
    // }
};
