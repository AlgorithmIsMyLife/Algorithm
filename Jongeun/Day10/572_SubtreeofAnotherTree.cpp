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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // check if it's the same as subtree
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        else if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }

        if (root->val == subRoot->val)
        {
            bool isSub = _isSubtree(root->left, subRoot->left) && _isSubtree(root->right, subRoot->right);
            if (isSub)
            {
                return true;
            }
        }
        // else
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool _isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // check if it's the same as subtree
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        else if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }

        // none of both are nullptr

        if (root->val == subRoot->val)
        {
            return _isSubtree(root->left, subRoot->left) && _isSubtree(root->right, subRoot->right);
        }
        else
        {
            return false;
        }
    }
};
