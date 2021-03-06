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
    bool isValidBST(TreeNode* root,TreeNode* l = NULL,TreeNode* r = NULL)
    {
         if(root == NULL)
                 return true;
         if(l!=NULL && l->val >= root->val)
                 return false;
         if(r!=NULL && r->val <= root->val)
                 return false;

         return isValidBST(root->left,l,root) && isValidBST(root->right,root,r);
    }
};