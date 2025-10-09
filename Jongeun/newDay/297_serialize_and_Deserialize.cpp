#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string s = "";
    _serialize(root, s);
    return s;
  }

  void _serialize(TreeNode *r, string &s) {
    if (r != nullptr) {
      s += (to_string(r->val) + "#");
      _serialize(r->left, s);
      _serialize(r->right, s);
    } else {
      s += "N#";
    }
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    TreeNode *root = nullptr;
    queue<string> q;
    int l = 0;
    int r = 0;

    while (r < data.size()) {
      while (data[r] != '#') {
        r++;
      }

      if (data[l] != 'N') {
        q.push(data.substr(l, r - l));

      } else {
        q.push("N");
      }

      r++;
      l = r;
    }

    _deserialize(&root, q);
    return root;
  }

  void _deserialize(TreeNode **r, queue<string> &q) {
    if (!q.empty()) {
      string temp = q.front();
      q.pop();

      if (temp != "N") {
        *r = new TreeNode(stoi(temp));
        _deserialize(&((*r)->left), q);
        _deserialize(&((*r)->right), q);
      }
    }
  }
};

int main() { Solution s{}; }
