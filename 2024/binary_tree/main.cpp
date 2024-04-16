#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <type_traits>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build_tree(TreeNode* root, TreeNode* left, TreeNode* right) {
  if (root == nullptr) {
    return nullptr;
  }
  root->left = left;
  root->right = right;
  return root;
}

void preorder_traversal(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  std::cout << root->val << " ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// leetcode 94
void inorder(TreeNode* root, vector<int>& res) {
  if (!root) return;
  inorder(root->left, res);
  res.push_back(root->val);
  inorder(root->right, res);
}

std::vector<int> inorderTraversal(TreeNode* root) {
  std::vector<int> res;
  inorder(root, res);
  return res;
}

vector<int> inorderTraversal1(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  TreeNode* cur = root;
  while (cur != nullptr || !st.empty()) {
    if (cur != nullptr) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      res.push_back(cur->val);
      cur = cur->right;
    }
  }
  return res;
}

// leetcode 98
bool isValidBST(TreeNode* root) {}

// leetcode 101
bool compare(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr)
    return true;
  else if (left != nullptr && right == nullptr)
    return false;
  else if (left == nullptr && right != nullptr)
    return false;
  else if (left->val != right->val)
    return false;

  bool outside = compare(left->left, right->right);
  bool inside = compare(left->right, right->left);
  bool is_same = outside && inside;
  return is_same;
}

bool isSymmetric(TreeNode* root) {
  if (root == nullptr) return true;
  return compare(root->left, root->right);
}

// leetcode 102
vector<vector<int>> levelOrder(TreeNode* root) {
  queue<TreeNode*> que;
  vector<vector<int>> res;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    vector<int> tmp;
    for (int i = que.size(); i > 0; --i) {
      root = que.front();
      que.pop();
      tmp.push_back(root->val);
      if (root->left != nullptr) que.push(root->left);
      if (root->right != nullptr) que.push(root->right);
    }
    res.push_back(tmp);
  }
  return res;
}

void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
  if (cur == nullptr) return;
  if (result.size() == depth) result.push_back({});
  result[depth].push_back(cur->val);
  order(cur->left, result, depth + 1);
  order(cur->right, result, depth + 1);
}

vector<vector<int>> levelOrder1(TreeNode* root) {
  vector<vector<int>> res;
  int depth = 0;
  order(root, res, depth);
  return res;
}

// leetcode 104
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth1(TreeNode* root) {
  if (root == nullptr) return 0;
  int depth = 0;
  queue<TreeNode*> que;
  que.push(root);
  while (!que.empty()) {
    int size = que.size();
    depth++;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return depth;
}

// leetcode 107
vector<vector<int>> levelOrderBottom(TreeNode* root) {
  queue<TreeNode*> que;
  vector<vector<int>> res;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    vector<int> tmp;
    for (int i = que.size(); i > 0; --i) {
      TreeNode* node = que.front();
      que.pop();
      tmp.push_back(node->val);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(tmp);
  }
  reverse(res.begin(), res.end());
  return res;
}

// leetcode 114
void traverse(vector<int>& vec, TreeNode* root) {
  if (root == nullptr) return;
  vec.push_back(root->val);
  traverse(vec, root->left);
  traverse(vec, root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> vec;
  traverse(vec, root);
  return vec;
}

vector<int> preorderTraversal1(TreeNode* root) {
  vector<int> vec;
  stack<TreeNode*> s;
  if (root == nullptr) return vec;
  s.push(root);
  while (!s.empty()) {
    TreeNode* node = s.top();
    s.pop();
    vec.push_back(node->val);
    if (node->right) s.push(node->right);
    if (node->left) s.push(node->left);
  }
  return vec;
}

// leetcode 116
/*
Node* connect(Node* root) {
  if (root == nullptr) return nullptr;
  traverse(root->left, root->right);
  return root;
}

void traverse(Node* node1, Node* node2) {
  if (node1 == nullptr || node2 == nullptr) {
    return;
  }
  node1->next = node2;
  traverse(node1->left, node1->right);
  traverse(node2->left, node2->right);
  traverse(node1->right, node2->left);
}

Node* connect1(Node* root) {
  queue<Node*> que;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    Node* node_pre;
    Node* node;
    for (int i = 0; i < size; ++i) {
      if (i == 0) {
        node_pre = que.front();
        que.pop();
        node = node_pre;
      } else {
        node = que.front();
        que.pop();
        node_pre->next = node;
        node_pre = node_pre->next;
      }
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    node_pre->next = nullptr;
  }
  return root;
}
*/

// leetcode 199
vector<int> rightSideView(TreeNode* root) {
  queue<TreeNode*> que;
  vector<int> res;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      if (i == (size - 1)) res.push_back(node->val);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return res;
}

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// leetcode 429
vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> res;
  queue<Node*> que;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    vector<int> tmp;
    for (int i = 0; i < size; ++i) {
      Node* node = que.front();
      que.pop();
      tmp.push_back(node->val);
      for (auto c : node->children) {
        if (c) que.push(c);
      }
    }
    res.push_back(tmp);
  }
  return res;
}

// leetcode 515
vector<int> largestValues(TreeNode* root) {
  vector<int> res;
  queue<TreeNode*> que;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    int max_value = INT_MIN;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      max_value = max(max_value, node->val);

      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(max_value);
  }
  return res;
}

// leetcode 559
int maxDepth(Node* root) {
  if (root == 0) return 0;
  int depth = 0;
  for (int i = 0; i < root->children.size(); i++) {
    depth = max(depth, maxDepth(root->children[i]));
  }
  return depth + 1;
}

// leetcode 637
vector<double> averageOfLevels(TreeNode* root) {
  vector<double> res;
  queue<TreeNode*> que;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    double sum = 0;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      sum += node->val;
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(sum / size);
  }
  return res;
}

/*
      1
    2   3
  4       5
  前序：1 2 4 3 5
  中序：4 2 1 3 5
  后序：4 2 5 3 1
*/

int main() {
  TreeNode* root = new TreeNode(1);
  TreeNode* left_child = new TreeNode(2);
  TreeNode* right_child = new TreeNode(3);
  TreeNode* left_grandchild = new TreeNode(4);
  TreeNode* right_grandchild = new TreeNode(5);

  root = build_tree(root, left_child, right_child);
  left_child = build_tree(left_child, left_grandchild, nullptr);
  right_child = build_tree(right_child, nullptr, right_grandchild);

  std::cout << "print: ";
  preorder_traversal(root);
  std::cout << "\n";

  delete left_grandchild;
  delete right_grandchild;
  delete left_child;
  delete right_child;
  delete root;

  return 0;
}