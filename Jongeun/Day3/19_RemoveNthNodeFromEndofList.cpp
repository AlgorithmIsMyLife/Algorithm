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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur = head;
        ListNode *tempt = head;

        // if(head->next == nullptr)
        // {
        //     return nullptr;
        // }

        for (int i{n - 1}; i > 0; i--)
        {
            tempt = tempt->next;
        }

        ListNode *pre = nullptr;
        while (tempt->next != nullptr)
        {
            pre = cur;
            cur = cur->next;
            tempt = tempt->next;
        }

        if (pre != nullptr)
        {
            pre->next = cur->next;
        }
        else
        {
            head = head->next;
        }

        delete cur;

        return head;
    }
};
