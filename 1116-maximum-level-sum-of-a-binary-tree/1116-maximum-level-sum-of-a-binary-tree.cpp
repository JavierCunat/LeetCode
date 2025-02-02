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
    int maxLevelSum(TreeNode* root) {
         //level order traversal store the max sum return that level
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        int max = INT_MIN;
        int maxLevel = 1;

        while(!q.empty()) {
            size_t size = q.size();
            int levelMax = 0;
            for(size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelMax += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelMax > max) {
                max = levelMax;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};