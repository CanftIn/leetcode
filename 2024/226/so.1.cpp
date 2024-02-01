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
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        traverse(root->left);
        traverse(root->right);
    }
};