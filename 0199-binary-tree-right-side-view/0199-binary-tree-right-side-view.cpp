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
//reviewed 8/31/2025
    vector<int> rightSideView(TreeNode* root) {
        //level order traversal and print the rightmost node aka last one in the queue
        queue<TreeNode*> q;
        vector<int> res;

        if(root == nullptr) return res;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(size_t i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(i == size-1) {
                    res.push_back(node->val);
                }
                
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }

        return res;
    }
};
