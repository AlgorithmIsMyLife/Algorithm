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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *cur = head;
        ListNode *initFront = new ListNode();
        ListNode *resultHead = initFront;

        while (cur != nullptr)
        {
            int i{0};
            ListNode *init = cur; // store the current node

            while (i < k - 1)
            {
                // check if it has sufficient k nodes
                cur = cur->next;
                if (cur == nullptr)
                {
                    // end of the list
                    break;
                }
                i++;
            }

            if (i == k - 1)
            {
                // k node exists -> 1 step move further
                cur = cur->next;
                // reverse k nodes
                ListNode *cur2 = init;
                ListNode *pre = cur;
                for (int j = 0; j < k; j++)
                {
                    ListNode *tempt = cur2->next;
                    cur2->next = pre;
                    pre = cur2;
                    cur2 = tempt;
                }

                // connect back
                init->next = cur;
                // connext front
                initFront->next = pre;
                // move initfront
                for (int j = 0; j < k; j++)
                {
                    initFront = initFront->next;
                }
            }
            else
            { // reach the end of the nodes
                break;
            }
        }

        return resultHead->next;
    }
};
