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
    bool isCompleteTree(TreeNode* root) {
    //level order traversal(BFS) when encounter a null node we shouldn't encounter any more for it to be compelte
        queue<TreeNode*> q;
        q.push(root);
        bool encounteredNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
            //if a null node is encountered, all subsequent nodes must also be null
             encounteredNull = true;
            } else {
            if (encounteredNull) {
                //if a non-null node is found after a null node tree is not complete
                return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};