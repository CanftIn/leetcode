#include <iostream>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0;
        sumPath(root, sum);
        return resSum;
    }
    
    void sumPath(TreeNode* root, int sum)
    {
        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            resSum += sum;
        if(root->left)
            sumPath(root->left, sum);
        if(root->right)
            sumPath(root->right, sum);
    }
private:
    int resSum;
};