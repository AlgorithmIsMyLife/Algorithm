/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        deque<pair<TreeNode *, int>> nodes;
        vector<vector<int>> levelOrder;

        pair<TreeNode *, int> first = make_pair(root, 0);
        nodes.emplace_back(first);
        while (!nodes.empty())
        {
            auto cur = nodes.front();
            nodes.pop_front();
            if (cur.first != nullptr)
            {
                if (cur.second < levelOrder.size())
                {
                    levelOrder[cur.second].push_back(cur.first->val);
                }
                else
                {
                    vector<int> t1;
                    t1.push_back(cur.first->val);
                    levelOrder.push_back(t1);
                }

                // insert childs
                pair<TreeNode *, int> tempt;
                if (cur.first->left != nullptr)
                {
                    tempt = make_pair(cur.first->left, cur.second + 1);
                    nodes.emplace_back(tempt);
                }

                if (cur.first->right != nullptr)
                {
                    tempt = make_pair(cur.first->right, cur.second + 1);
                    nodes.emplace_back(tempt);
                }
            }
        }

        return levelOrder;
    }
};
