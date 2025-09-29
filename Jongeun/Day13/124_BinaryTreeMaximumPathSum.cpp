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
    int maxPathSum(TreeNode *root)
    {
        int max = INT_MIN;
        _maxPathSum(root, max);
        return max;
    }

    int _maxPathSum(TreeNode *node, int &max)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = _maxPathSum(node->left, max);
        int right = _maxPathSum(node->right, max);

        int win = std::max(left, right);

        // set the Max
        int temptMax = win;
        if (left + right > win)
        {
            // combine the both path
            temptMax = left + right;
        }

        // check if it should the child path
        if (temptMax > 0)
        {
            temptMax = temptMax + node->val;
        }
        else
        {
            temptMax = node->val;
        }

        if (temptMax > max)
        {
            max = temptMax;
        }

        // return the node->val or node->val + win
        if (win > 0)
        {
            return win + node->val;
        }
        else
        {
            return node->val;
        }
    }
};
