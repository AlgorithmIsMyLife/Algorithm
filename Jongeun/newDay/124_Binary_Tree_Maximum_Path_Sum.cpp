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

// 초기 코드
//  class Solution {
//  public:
//    int maxPathSum(TreeNode *root) {
//      int minV = -1001;
//      dfs(root, minV);
//      return minV;
//    }
//
//    int dfs(TreeNode *node, int &maxRes) {
//      if (!node)
//        return -1001;
//
//      int l = dfs(node->left, maxRes);
//      int r = dfs(node->right, maxRes);
//      int sum = l + r;
//      int maxChild = (l >= r) ? l : r;
//      int choice;
//      if (sum >= maxChild) {
//        // 두개 자식 선택
//        choice = sum;
//      } else {
//        choice = maxChild;
//      }
//
//      int choice2;
//      sum = choice + node->val;
//      if (sum >= node->val) {
//        choice2 = sum;
//      } else {
//        choice2 = node->val;
//      }
//      maxRes = max(maxRes, choice2);
//
//      if (maxChild + node->val >= node->val) {
//        return maxChild + node->val;
//      } else {
//        return node->val;
//      }
//    }
//  };

// 깔끔한 버전
class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int minV = -1001;
    dfs(root, minV);
    return minV;
  }

  int dfs(TreeNode *node, int &maxRes) {
    if (!node)
      return 0;

    int l = max(dfs(node->left, maxRes), 0);
    int r = max(dfs(node->right, maxRes), 0);

    maxRes = max(maxRes, node->val + l + r);

    return node->val + max(l, r);
  }

}

  int main() {
  Solution s{};
}
