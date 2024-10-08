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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p->val == q->val)
        {
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution isSameTree;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);

    cout << isSameTree.isSameTree(p, q) << endl;

    return 0;
}
