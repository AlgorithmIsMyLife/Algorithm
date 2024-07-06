/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        int n{0};

        ListNode *newHead = new ListNode();
        ListNode *copy = newHead;
        ListNode *cur = head;

        // make the copy
        while (cur != nullptr)
        {
            newHead->next = new ListNode();
            newHead->next->val = cur->val;
            newHead = newHead->next;

            cur = cur->next;
            n++;
        }

        int loop = 0;

        if (n % 2 == 0)
        {
            loop = n / 2;
        }
        else
        {
            loop = n / 2 + 1;
        }

        // Reverse version
        ListNode *pre = nullptr;
        cur = copy->next;
        ListNode *reverseHead = cur;
        while (cur != nullptr)
        {
            ListNode *tempt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tempt;
        }

        // connect
        cur = head;
        ListNode *cur2 = pre;
        while (loop > 0)
        {
            ListNode *tempt = cur->next;
            ListNode *tempt2 = cur2->next;
            cur->next = cur2;
            cur2->next = tempt;
            cur = tempt;
            cur2 = tempt2;
            loop--;
        }

        cur = head;
        for (int i = n - 1; i > 0; i--)
        {
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};
