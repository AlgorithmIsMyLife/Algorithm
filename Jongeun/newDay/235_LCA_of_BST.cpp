#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> parent(201);
    unordered_map<TreeNode *, int> depth;
    queue<TreeNode *> qq;
    depth[root] = 0;
    qq.push(root);

    while (!qq.empty()) {
      TreeNode *node = qq.front();
      qq.pop();
      if (node->left) {
        qq.push(node->left);
        depth[node->left] = depth[node] + 1;
        int idx = node->left->val;
        parent[idx + 100] = node;
      }

      if (node->right) {
        qq.push(node->right);
        depth[node->right] = depth[node] + 1;
        int idx = node->right->val;
        parent[idx + 100] = node;
      }
    }

    int pDepth = depth[p];
    int qDepth = depth[q];

    if (pDepth > qDepth) {
      while (pDepth != qDepth) {
        p = parent[p->val + 100];
        pDepth--;
      }

    } else {
      while (pDepth != qDepth) {
        q = parent[q->val + 100];
        qDepth--;
      }
    }

    while (p != q) {
      p = parent[p->val + 100];
      q = parent[q->val + 100];
    }

    return p;
  }
};
int main() { Solution s{}; }
