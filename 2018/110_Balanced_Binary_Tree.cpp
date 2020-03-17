#include <iostream>
#include <algorithm>

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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
            
        int LeftDepth = getDepth(root->left);
        int RightDepth = getDepth(root->right);
        if(abs(LeftDepth - RightDepth) > 1)
            return false;
        return true;
    }
    
    int getDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right)); 
    }
};