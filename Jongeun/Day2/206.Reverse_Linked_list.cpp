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
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *cur = head;
        ListNode *pre = nullptr;

        while (cur != nullptr)
        {
            ListNode *tempt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tempt;
        }
        return pre;
    }
};
