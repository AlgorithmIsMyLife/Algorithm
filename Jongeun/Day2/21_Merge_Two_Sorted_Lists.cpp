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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *tempt1 = list1;
        ListNode *tempt2 = list2;

        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *head = new ListNode();
        ListNode *cur = head;

        while (tempt1 != nullptr && tempt2 != nullptr)
        {
            if (tempt1->val < tempt2->val)
            {
                cur->next = tempt1;
                tempt1 = tempt1->next;
            }
            else
            {
                cur->next = tempt2;
                tempt2 = tempt2->next;
            }

            cur = cur->next;
        }

        if (tempt1 == nullptr)
        {
            cur->next = tempt2;
        }
        else if (tempt2 == nullptr)
        {
            cur->next = tempt1;
        }

        return head->next;
    }
};
