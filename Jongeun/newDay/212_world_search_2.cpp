class TrieNode {
public:
  TrieNode *children[26];
  bool isEnd;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    isEnd = false;
  }
};

class Trie {
public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void Insert(string word) {
    TrieNode *cur = root;
    for (auto c : word) {
      if (cur->children[c - 'a'] == nullptr) {
        TrieNode *temp = new TrieNode();
        cur->children[c - 'a'] = temp;
      }
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int m = board.size();
    int n = board[0].size();
    Trie *trie = new Trie();
    vector<string> res;

    for (auto &str : words) {
      trie->Insert(str);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // construct the trie based on the board
        _findWords(board, trie->root, res, "", m, n, i, j);
      }
    }

    return res;
  }

  void _findWords(vector<vector<char>> &board, TrieNode *node,
                  vector<string> &res, string str, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
      return;
    }

    char c = board[i][j];
    str += c;

    TrieNode *cur = node->children[c - 'a'];
    if (cur == nullptr) {
      return;
    }

    if (cur->isEnd == true) {
      res.push_back(str);
      cur->isEnd = false;
    }

    board[i][j] = '#';
    _findWords(board, node->children[c - 'a'], res, str, m, n, i - 1, j);
    _findWords(board, node->children[c - 'a'], res, str, m, n, i, j - 1);
    _findWords(board, node->children[c - 'a'], res, str, m, n, i, j + 1);
    _findWords(board, node->children[c - 'a'], res, str, m, n, i + 1, j);
    board[i][j] = c;
  }
};
