
    TrinULL)1  {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
        res.push_back(root->val);
        helper(res, root->right);
    }
};

    void helper(vector<int>& res, TreeNode* root)
    {
        if(root == NULL) return ;
        helper(res, root->left);
        res.push_back(root->val);
        helper(res, root->right);
    }
};

// LeetCode, Binary Tree Inorder Traversal
// Morris O(n)  O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                    node->right = cur;
                    cur = cur->left;
                } else {
                    result.push_back(cur->val);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};