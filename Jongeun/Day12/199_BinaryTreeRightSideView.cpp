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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> nodes;
        queue<TreeNode *> q;

        if (root == nullptr)
        {
            return nodes;
        }

        q.emplace(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();

                if (temp->left != nullptr)
                {
                    q.emplace(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.emplace(temp->right);
                }
                q.pop();

                if (i == size - 1)
                {
                    nodes.push_back(temp->val);
                }
            }
        }

        return nodes;
    }
};
