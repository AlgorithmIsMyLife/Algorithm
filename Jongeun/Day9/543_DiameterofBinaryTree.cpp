#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {

        int tempt = _diameterOfBinaryTree(root);
        return diameter;
    }

    int _diameterOfBinaryTree(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = 0, right = 0;
        if (node->left != nullptr)
        {
            left = 1 + diameterOfBinaryTree(node->left);
        }
        if (node->right != nullptr)
        {
            right = 1 + diameterOfBinaryTree(node->right);
        }

        int diameter1 = left + right;
        if (diameter < diameter1)
        {
            diameter = diameter1;
        }
        return max(left, right);
    }

private:
    int diameter{0};
};

int main()
{
    Solution diameterOfBinaryTree;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree.diameterOfBinaryTree(root) << endl;
    return 0;
}
