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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int m = 0;
        int i = 0;
        while (preorder[0] != inorder[m])
        {
            m++;
        }
        // l : range of  my left subtree
        // r : range of my right subtree
        TreeNode *node = _buildTree(preorder, inorder, 0, m, inorder.size() - 1, i);
        return node;
    }

    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int l, int m, int r, int &i)
    {
        TreeNode *node = new TreeNode(preorder[i]);
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        i++;

        // check if it is in left subtree
        int tempt = m - 1;
        while (tempt >= l && preorder[i] != inorder[tempt])
        {
            tempt--;
        }
        if (tempt >= l)
        {
            // in the left subtree
            left = _buildTree(preorder, inorder, l, tempt, m - 1, i);
        }

        // check if it is in the right subtree
        tempt = m + 1;
        while (tempt <= r && preorder[i] != inorder[tempt])
        {
            tempt++;
        }
        if (tempt <= r)
        {
            // in the right subtree
            right = _buildTree(preorder, inorder, m + 1, tempt, r, i);
        }

        node->left = left;
        node->right = right;

        return node;
    }
};
