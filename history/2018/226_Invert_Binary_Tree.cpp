#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(&root->left, &root->right);
        return root;
    }
    
    void swap(TreeNode **a, TreeNode **b)
    {
        TreeNode *temp = *a;
        *a = *b;
        *b = temp;
    }
};