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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            //found the node to delete
            if (root->left == nullptr && root->right == nullptr) {
                //node has no children
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;//return the right subtree
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;//return the left subtree
            } else {
                //node has two children
                //find the in-order predecessor (rightmost node of the left subtree)
                TreeNode* temp = root->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }

        //always return the root of the entire tree
        return root;
    }
};