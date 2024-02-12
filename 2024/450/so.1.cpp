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
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            TreeNode* min_node = getMin(root->right);
            root->right = deleteNode(root->right, min_node->val);
            min_node->left = root->left;
            min_node->right = root->right;
            root = min_node;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
};