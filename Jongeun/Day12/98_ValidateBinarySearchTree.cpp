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
    bool isValidBST(TreeNode *root)
    {
        bool isValid = true;
        vector<int> nodes;
        _isValidBST(root, nodes);

        int temp = nodes[0];

        for (int i = 1; i < nodes.size(); i++)
        {
            if (nodes[i] <= temp)
            {
                isValid = false;
            }
            temp = nodes[i];
        }

        return isValid;
    }
    void _isValidBST(TreeNode *node, vector<int> &nodes)
    {
        if (node == nullptr)
        {
            return;
        }

        _isValidBST(node->left, nodes);
        nodes.push_back(node->val);
        _isValidBST(node->right, nodes);
    }
};
