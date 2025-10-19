#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dx{1, 0, -1, 0};
  vector<int> dy{0, 1, 0, -1};

  struct TrieNode {
    TrieNode *children[26];

    TrieNode() {
      for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
      }
    }
  };

  static inline int idx(char c) { return c - 'a'; }

  void insert(TrieNode *root, const string &key) {
    TrieNode *curr = root;
    for (char c : key) {
      int i = idx(c);
      if (i < 0 || i >= 26)
        return;
      if (!curr->children[i])
        curr->children[i] = new TrieNode();
      curr = curr->children[i];
    }
  }

  bool search(TrieNode *root, const string &key) {
    if (!root)
      return false;
    TrieNode *curr = root;
    for (char c : key) {
      int i = idx(c);
      if (i < 0 || i >= 26)
        return false;
      if (!curr->children[i])
        return false;
      curr = curr->children[i];
    }
    return true;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    TrieNode *root = new TrieNode();
    string temp = "";
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col));

    dfs(i, j, row, col, root, board, temp, visited);

    vector<string> output;

    for (auto &s : words) {
      if (search(root, s)) {
        output.push_back(s);
      }
    }

    return output;
  }

  void dfs(int i, int j, int row, int col, TrieNode *root,
           vector<vector<char>> &board, string &temp,
           vector<vector<bool>> &visited) {

    if (i < 0 || i >= row || j < 0 || j >= col) {
      insert(root, temp);
      string copy(temp);
      reverse(copy.begin(), copy.end());
      insert(root, copy);
      return;
    }
    if (visited[i][j]) {
      return;
    }
    temp += board[i][j];
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
      dfs(i + dy[k], j + dx[k], row, col, root, board, temp, visited);
    }

    visited[i][j] = false;
    if (!temp.empty())
      temp.pop_back();
  }
};

int main() { Solution s{}; }
