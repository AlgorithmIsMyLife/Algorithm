/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        vector<Node *> nodes(101, nullptr);
        vector<bool> visited(101, false);
        queue<Node *> q;
        q.push(node);

        if (node == nullptr)
        {
            return nullptr;
        }

        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            vector<Node *> cpNeighbors;

            for (auto n : cur->neighbors)
            {
                if (!visited[n->val])
                {
                    q.push(n);
                    if (!nodes[n->val])
                    {
                        // Not exist
                        Node *temp = new Node(n->val);
                        nodes[n->val] = temp;
                    }
                }

                // Add a neighbor
                cpNeighbors.push_back(nodes[n->val]);
            }

            if (!nodes[cur->val])
            {
                // not existed
                Node *newNode = new Node(cur->val, cpNeighbors);
                nodes[cur->val] = newNode;
                visited[cur->val] = true;
            }
            else
            {
                nodes[cur->val]->neighbors = cpNeighbors;
                visited[cur->val] = true;
            }
        }

        return nodes[1];
    }
};
