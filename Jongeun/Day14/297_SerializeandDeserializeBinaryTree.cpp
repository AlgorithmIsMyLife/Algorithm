#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root != nullptr)
        {
            q.push(root);
        }
        else
        {
            return "";
        }

        string s = "";
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            s += to_string(temp->val);

            if (temp->left)
            {
                q.push(temp->left);
                s = s + "L" + to_string(temp->left->val);
            }
            if (temp->right)
            {
                q.push(temp->right);
                s = s + "R" + to_string(temp->right->val);
            }

            s += " "; // delimiter
            q.pop();
        }

        return s;
    }

    // Decodes your encoded data to tree.

    TreeNode *deserialize(string data)
    {

        int l{0};
        int r{0};

        if (data == "")
        {
            return nullptr;
        }

        queue<TreeNode *> q;

        while (data[r] != 'L' && data[r] != 'R' && data[r] != ' ')
        {
            r++;
        }

        TreeNode *head = new TreeNode(stoi(data.substr(l, r - l)));
        q.push(head);

        while (r < data.size())
        {

            TreeNode *temp = q.front();

            while (data[r] != 'L' && data[r] != 'R' && data[r] != ' ')
            {
                r++;
            }

            if (data[r] == 'L')
            {
                r++;
                l = r;

                while (data[r] != 'R' && data[r] != ' ')
                {
                    r++;
                }

                TreeNode *leftNode = new TreeNode(stoi(data.substr(l, r - l)));
                temp->left = leftNode;
            }

            if (data[r] == 'R')
            {
                r++;
                l = r;

                while (data[r] != ' ')
                {
                    r++;
                }

                TreeNode *rightNode = new TreeNode(stoi(data.substr(l, r - l)));
                temp->right = rightNode;
            }

            if (data[r] == ' ')
            {
                r++;
                l = r;
            }

            q.pop();
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    Codec ser, deser;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = ser.serialize(root);
    cout << s << endl;

    TreeNode *ans = deser.deserialize(s);
    cout << ans->val << endl;
    cout << ans->left->val << endl;
    cout << ans->right->val << endl;
    cout << ans->right->left->val << endl;
    cout << ans->right->right->val << endl;

    return 0;
}
