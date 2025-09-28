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
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;

    if (cur == nullptr) {
      return nullptr;
    }

    while (cur->next != nullptr) {
      ListNode *temp = cur->next;
      cur->next = temp->next;
      temp->next = head;
      head = temp;
    }

    return head;
  }
};

int main() { Solutin s{}; }
