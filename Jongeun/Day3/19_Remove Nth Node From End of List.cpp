// #include <iostream>

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution
// {

// public:
//     struct ListNode
//     {
//         int val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
//     };

// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         ListNode *cur = head;
//         ListNode *tempt = head;

//         for (int i{n - 1}; i > 0; i--)
//         {
//             tempt = tempt->next;
//         }

//         ListNode *pre = nullptr;
//         while (tempt->next != nullptr)
//         {
//             pre = cur;
//             cur = cur->next;
//             tempt = tempt->next;
//         }

//         pre->next = cur->next;
//         delete cur;

//         return head;
//     }
// };

// int main()
// {
//     Solution s;
//     Solution::ListNode *head = new Solution::ListNode(1);
//     head->next = new Solution::ListNode(2);
//     head->next->next = new Solution::ListNode(3);
//     head->next->next->next = new Solution::ListNode(4);
//     head->next->next->next->next = new Solution::ListNode(5);

//     Solution::ListNode *result = s.removeNthFromEnd(head, 2);

//     while (result != nullptr)
//     {
//         std::cout << result->val << " ";
//         result = result->next;
//     }

//     return 0;
// }
