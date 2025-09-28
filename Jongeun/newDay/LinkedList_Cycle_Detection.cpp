#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // Version 1. Hash set
  // bool hasCycle(ListNode *head) {
  //   unordered_map<ListNode*, bool> um;
  //   ListNode* cur = head;
  //
  //   while(cur != nullptr)
  //   {
  //     if(um[cur] ==true)
  //     {
  //       return true;
  //     }
  //
  //     um[cur] = true;
  //
  //     cur = cur->next;
  //   }
  //
  //   return false;
  //
  //
  // }
  //
  //
  // Version 2. Fast and Slow pointer
  class Solution {
  public:
    bool hasCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;

      while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
          return true;
      }

      return false;
    }
  };
};

int main() { Solutin s{}; }
