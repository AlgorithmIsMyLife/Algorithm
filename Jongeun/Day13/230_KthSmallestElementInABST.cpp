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
    int kthSmallest(TreeNode *root, int k)
    {
        int order{0};
        return _kthSmallest(root, k, order);
    }

    int _kthSmallest(TreeNode *node, int k, int &order)
    {

        if (node == nullptr)
        {
            return -1;
        }

        int l = _kthSmallest(node->left, k, order);

        order++;
        if (order == k)
        {
            return node->val;
        }

        int r = _kthSmallest(node->right, k, order);

        if (l != -1)
        {
            return l;
        }
        else if (r != -1)
        {
            return r;
        }

        return -1;
    }
};
