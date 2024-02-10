#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* pre;
    TreeNode* node1;
    TreeNode* node2;
    
    void backtracking(TreeNode* node) {
        if (node == NULL) return;
        
        backtracking(node->left);
        
        // 若不是第一个节点，node1之前没有出现，但是现在出现了，记录下来(node1 被记录下后就不会变)
        if (pre != NULL && node1 == NULL && node->val < pre->val) node1 = pre;
        
        // 若不是第一个节点，node1 出现了，且满足node2的条件，记录下来
        if (pre != NULL && node1 != NULL && node->val < pre->val) node2 = node;
        
        pre = node;
        
        backtracking(node->right);
    }
    
    void recoverTree(TreeNode* root) {
        backtracking(root);
        swap(node1->val, node2->val);
    }
};

// 辅助函数，根据输入数组创建二叉树
TreeNode* createTree(const vector<int>& arr, int index) {
    TreeNode* node = NULL;
    if (index < arr.size() && arr[index] != -1) {
        node = new TreeNode(arr[index]);
        node->left = createTree(arr, 2 * index + 1);
        node->right = createTree(arr, 2 * index + 2);
    }
    return node;
}

// 辅助函数，释放二叉树内存
void deleteTree(TreeNode* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// 辅助函数，中序遍历打印二叉树
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // 测试用例
    vector<int> arr = {1, 3, -1, -1, 2}; // 输入数组
    TreeNode* root = createTree(arr, 0); // 创建二叉树
    
    // 打印原始二叉树
    cout << "Original tree: ";
    inorderTraversal(root);
    cout << endl;
    
    // 恢复二叉搜索树
    Solution solution;
    solution.recoverTree(root);
    
    // 打印恢复后的二叉树
    cout << "Recovered tree: ";
    inorderTraversal(root);
    cout << endl;
    
    // 释放内存
    deleteTree(root);
    
    return 0;
}
