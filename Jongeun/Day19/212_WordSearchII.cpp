#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    bool Search(string word)
    {
        TrieNode *cur = root;
        for (auto c : word)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                return false;
            }

            cur = cur->children[c - 'a'];
        }

        return cur->isEnd;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size();
        int n = board[0].size();
        Trie *trie = new Trie();
        vector<string> res;

        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; < 1; j++)
            {
                // construct the trie based on the board
                constructTrie(board, trie->root, m, n, i, j);
            }
        }

        // search
        for (string &str : words)
        {
            if (trie->Search(str))
            {
                res.push_back(str);
            }
        }

        return res;
    }

    void constructTrie(vector<vector<char>> &board, TrieNode *node, int m, int n, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            // previous node
            node->isEnd = true;
            return;
        }

        // already visited
        if (board[i][j] == '#')
        {
            node->isEnd = true;
            return;
        }

        char c = board[i][j];

        if (node->children[c - 'a'] == nullptr)
        {
            TrieNode *temp = new TrieNode();
            node->children[c - 'a'] = temp;
        }

        board[i][j] = '#';
        constructTrie(board, node->children[c - 'a'], m, n, i - 1, j);
        constructTrie(board, node->children[c - 'a'], m, n, i, j - 1);
        constructTrie(board, node->children[c - 'a'], m, n, i, j + 1);
        constructTrie(board, node->children[c - 'a'], m, n, i + 1, j);
        board[i][j] = c;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> res = sol.findWords(board, words);

    for (string &str : res)
    {
        cout << str << " ";
    }

    return 0;
}
