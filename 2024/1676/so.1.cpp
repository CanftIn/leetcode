#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, std::vector<TreeNode*>& nodes) {
        // 将列表转化成哈希集合，便于判断元素是否存在
        std::unordered_set<int> values;
        for (TreeNode* node : nodes) {
            values.insert(node->val);
        }
        return find(root, values);
    }

private:
    // 在二叉树中寻找 values 的最近公共祖先节点
    TreeNode* find(TreeNode* root, const std::unordered_set<int>& values) {
        if (root == nullptr) {
            return nullptr;
        }
        // 前序位置
        if (values.find(root->val) != values.end()) {
            return root;
        }
        
        TreeNode* left = find(root->left, values);
        TreeNode* right = find(root->right, values);
        // 后序位置，已经知道左右子树是否存在目标值
        if (left != nullptr && right != nullptr) {
            // 当前节点是 LCA 节点
            return root;
        }

        return (left != nullptr) ? left : right;
    }
};
