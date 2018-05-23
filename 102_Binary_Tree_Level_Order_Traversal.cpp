#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        
        q.push(root);
        do {
            vector<int> g;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front(); q.pop();
                if (t) {
                    g.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
            }
            if (g.size()) v.push_back(g);
        } while (!q.empty());

        return v;
    }
};