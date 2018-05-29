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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        helper(res, root);
        return res;
    }
    
private:
    void helper(vector<int>& res, TreeNode* root)
    {
        if(root == NULL) return ;
        res.push_back(root->val);
        helper(res, root->left);
        helper(res, root->right);
    }
};

// LeetCode, Binary Tree Preorder Traversal
// Morris O(n) O(1)
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;
                if (node->right == nullptr) {
                    result.push_back(cur->val);
                    node->right = cur;
                    prev = cur;
                    cur = cur->left;
                } else {
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};