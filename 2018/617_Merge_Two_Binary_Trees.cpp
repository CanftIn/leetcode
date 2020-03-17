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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        dfs(t1, t2);
        if(t1 == NULL)
            return t2;
        else
            return t1;
    }
    
    void dfs(TreeNode* t1, TreeNode* t2)
    {
        if(t1 != NULL && t2 != NULL)
        {
            t1->val += t2->val;
            if(t1->left && t2->left)
            {
                dfs(t1->left, t2->left);
            }
            else if(t1->left == NULL){
                t1->left = t2->left;
            }

            if(t1->right && t2->right){
                dfs(t1->right, t2->right);
            }
            else if(t1->right == NULL){
                t1->right = t2->right;
            }
        }
    }
};