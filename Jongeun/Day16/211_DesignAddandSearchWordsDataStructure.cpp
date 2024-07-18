
struct TrieNode
{
    TrieNode *ChildNode[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            ChildNode[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *cur = root;
        for (auto c : word)
        {
            if (cur->ChildNode[c - 'a'] == nullptr)
            {
                TrieNode *temp = new TrieNode();
                cur->ChildNode[c - 'a'] = temp;
                cur = temp;
            }
            else
            {
                cur = cur->ChildNode[c - 'a'];
            }
        }

        cur->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *cur = root;
        return _search(root, word);
    }

    bool _search(TrieNode *node, string word)
    {
        if (word.empty())
        {
            return node->isEnd == true;
        }

        TrieNode *cur = node;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                bool searched = false;
                for (int j = 0; j < 26; j++)
                {
                    if (cur->ChildNode[j] != nullptr)
                    {
                        searched = _search(cur->ChildNode[j], word.substr(i + 1));
                    }
                    if (searched == true)
                    {
                        return true;
                    }
                }

                return false;
            }
            else if (cur->ChildNode[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            else
            {
                cur = cur->ChildNode[word[i] - 'a'];
            }
        }

        return cur->isEnd == true;
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
