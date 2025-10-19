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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;

    queue<TreeNode *> q;
    q.push(root);

    int n = 1;
    while (!q.empty()) {
      int k = 0;
      vector<int> input;
      while (n) {
        TreeNode *temp = q.front();
        input.push_back(temp->val);
        q.pop();
        if (temp->left) {
          q.push(temp->left);
          k++;
        }
        if (temp->right) {
          q.push(temp->right);
          k++;
        }
        n--;
      }
      res.push_back(input);

      n = k;
    }

    return res;
  }
};

int main() { Solution s{}; }
