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
    int max_diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return max_diameter;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        int tmp_diameter = left_max + right_max;
        max_diameter = max(max_diameter, tmp_diameter);
        traverse(root->left);
        traverse(root->right);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return 1 + max(left_max, right_max);
    }
};