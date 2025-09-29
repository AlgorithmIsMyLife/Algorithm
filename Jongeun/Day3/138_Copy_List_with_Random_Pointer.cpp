/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        vector<Node *> CopynodeList{};
        unordered_map<Node *, int> Originalnodes; // node , index mapping
        Node *cur = head;
        Node *newCur = new Node(head->val);
        Node *newHead = newCur;

        CopynodeList.push_back(newCur);

        // push the nodes to the vector for indexing
        int j = 0;
        while (cur != nullptr)
        {
            Originalnodes[cur] = j++;
            cur = cur->next;
        }

        Originalnodes[nullptr] = j;

        cur = head->next; // next node
        int i = 1;
        while (cur != nullptr)
        {
            Node *tempt = new Node(cur->val);
            newCur->next = tempt;
            newCur = newCur->next;
            CopynodeList.push_back(newCur);
            cur = cur->next;
        }

        CopynodeList.push_back(nullptr);

        cur = head;
        newCur = newHead;
        while (cur != nullptr)
        {
            newCur->random = CopynodeList[Originalnodes[cur->random]];
            cur = cur->next;
            newCur = newCur->next;
        }

        return newHead;
    }
};
