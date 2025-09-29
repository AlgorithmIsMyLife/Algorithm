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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        int sum = 0;

        ListNode *head = new ListNode();
        ListNode *cur3 = head;

        while (cur1 != nullptr || cur2 != nullptr)
        {
            if (cur1 == nullptr)
            {
                sum = cur2->val + carry;
                if (sum >= 10)
                {
                    carry = 1;
                    sum -= 10;
                }
                else
                {
                    carry = 0;
                }

                cur3->next = new ListNode(sum);
                cur3 = cur3->next;
                cur2 = cur2->next;
            }
            else if (cur2 == nullptr)
            {
                sum = cur1->val + carry;
                if (sum >= 10)
                {
                    carry = 1;
                    sum -= 10;
                }
                else
                {
                    carry = 0;
                }

                cur3->next = new ListNode(sum);
                cur3 = cur3->next;
                cur1 = cur1->next;
            }
            else
            {
                // None of both are nullptr
                sum = cur1->val + cur2->val + carry;
                if (sum >= 10)
                {
                    carry = 1;
                    sum -= 10;
                }
                else
                {
                    carry = 0;
                }
                cur3->next = new ListNode(sum);

                cur1 = cur1->next;
                cur2 = cur2->next;
                cur3 = cur3->next;
            }
        }

        if (carry == 1)
        {
            cur3->next = new ListNode(1);
        }

        return head->next;
    }
};
