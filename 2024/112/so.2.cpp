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
    bool traversal(TreeNode* cur, int count){
        if(cur->left == NULL && cur->right == NULL && count == 0) return true;
        if(cur->left == NULL && cur->right == NULL && count != 0) return false;
        
        if(cur->left != NULL){
            count -= cur->left->val;
            if(traversal(cur->left, count)) return true;
            count += cur->left->val;
        }
        if(cur->right != NULL){
            count -= cur->right->val;
            if(traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};