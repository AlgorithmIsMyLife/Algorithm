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
    bool isBalanced(TreeNode *root)
    {
        _isBalanced(root);
        return IsBalanced;
    }

    int _isBalanced(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = _isBalanced(node->left);
        int right = _isBalanced(node->right);

        if (abs(left - right) > 1)
        {
            IsBalanced = false;
        }
        return 1 + max(left, right);
    }

private:
    bool IsBalanced = true;
};
