#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> ancestors;

        HasChilds(root, p, q, ancestors);
        return ancestors.front();
    }

    int HasChilds(TreeNode *node, TreeNode *p, TreeNode *q, vector<TreeNode *> &ac)
    {
        if (node != nullptr)
        {
            int curFound = 0;
            if (node->val == p->val || node->val == q->val)
            {
                curFound++;
            }

            int check;
            if (node->left == nullptr && node->right == nullptr)
            {
                return curFound;
            }
            else if (node->left == nullptr)
            {
                check = HasChilds(node->right, p, q, ac);
            }
            else if (node->right == nullptr)
            {
                check = HasChilds(node->left, p, q, ac);
            }
            else
            {
                check = HasChilds(node->left, p, q, ac) + HasChilds(node->right, p, q, ac);
            }

            if (curFound + check == 2)
            {
                ac.push_back(node);
            }
        }
        return 0;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution s;
    TreeNode *p = root->left;
    TreeNode *q = root->left->right;
    TreeNode *lca = s.lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;
    return 0;
}
