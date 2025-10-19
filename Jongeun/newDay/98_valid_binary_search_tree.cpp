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
  bool isValidBST(TreeNode *root) {
    bool res = true;
    int minV = -1001;
    inWalk(root, minV, res);
    return res;
  }

  void inWalk(TreeNode *node, int &pre, bool &res) {
    if (!node)
      return;

    inWalk(node->left, pre, res);
    if (pre >= node->val) {
      res = false;
    }
    pre = node->val;

    inWalk(node->right, pre, res);
  }
};

int main() { Solution s{}; }
