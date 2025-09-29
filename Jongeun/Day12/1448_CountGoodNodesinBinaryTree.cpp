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
    int goodNodes(TreeNode *root)
    {

        int max = root->val;
        int good = _goodNodes(root, max);
        return good;
    }

    int _goodNodes(TreeNode *node, int max)
    {
        if (node != nullptr)
        {
            int good;
            int newMax;
            if (node->val >= max)
            {
                good = 1;
                newMax = node->val;
            }
            else
            {
                good = 0;
                newMax = max;
            }
            int leftGoods = 0;
            int rightGoods = 0;

            if (node->left != nullptr)
            {
                leftGoods = _goodNodes(node->left, newMax);
            }

            if (node->right != nullptr)
            {
                rightGoods = _goodNodes(node->right, newMax);
            }

            return good + leftGoods + rightGoods;
        }

        return 0;
    }
};
