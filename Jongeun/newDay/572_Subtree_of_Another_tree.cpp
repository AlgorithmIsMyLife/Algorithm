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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    bool ret = false;
    dfs(root, subRoot, ret);
    return ret;
  }

  void dfs(TreeNode *node, TreeNode *subNode, bool &ret) {
    if (node == nullptr) {
      return;
    }

    if (node->val == subNode->val) {
      if (isCheck(node, subNode)) {
        ret = true;
      }
    }
    dfs(node->left, subNode, ret);
    dfs(node->right, subNode, ret);
  }

  bool isCheck(TreeNode *node, TreeNode *subNode) {
    if (subNode == nullptr && node == nullptr) {
      return true;
    }
    if (node && subNode == nullptr) {
      return false;
    }
    if (subNode && node == nullptr) {
      return false;
    }
    if (node->val != subNode->val) {
      return false;
    }

    bool temp = isCheck(node->left, subNode->left);
    bool temp2 = isCheck(node->right, subNode->right);
    return temp && temp2;
  }
};

int main() { Solution s{}; }
