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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        helper(res, root);
        return res;
    }
    
private:
    void helper(vector<int>& res, TreeNode* root)
    {
        if(root == NULL) return ;
        helper(res, root->left);
        helper(res, root->right);
        res.push_back(root->val);
    }
};

// LeetCode, Binary Tree Postorder Traversal
// Morris  O(n) O(1)
// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
