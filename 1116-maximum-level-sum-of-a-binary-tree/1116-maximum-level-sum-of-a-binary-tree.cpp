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
private:
    void dfs(vector<int>& level_sum, int cur_level, TreeNode *root) {
        //reviewed 12/6/2025
        if (!root) return;

        if (level_sum.size() <= cur_level) {
            level_sum.push_back(root -> val);
        } else {
            level_sum[cur_level] += root -> val;
        }

        dfs(level_sum, cur_level+1, root -> left);
        dfs(level_sum, cur_level+1, root -> right);
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        dfs(sums, 0, root);

        int max = INT_MIN;
        int max_i = -1;

        for(int i=0; i < sums.size(); i++) {
            if(sums[i] > max){
                max = sums[i];
                max_i = i;
            }
        }


        return max_i + 1;
    }
};
