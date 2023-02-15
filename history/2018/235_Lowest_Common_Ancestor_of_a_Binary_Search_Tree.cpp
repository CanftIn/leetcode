/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return go(root,p,q);
    }
private:
    bool find(TreeNode* root, TreeNode* target){
        if (!root) return false;
        return root==target ? true : find(root->left,target) || find(root->right,target);
    }
    TreeNode* go(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root==p || root==q) return root;
        if (find(root->left,p) && find(root->left,q)) return go(root->left,p,q);
        if (find(root->right,p) && find(root->right,q)) return go(root->right,p,q);
        return root;
    }
};