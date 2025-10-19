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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;

    int start = 0;
    int end = lists.size() - 1;
    mergeSort(start, end, lists);
    return lists[start];
  }

  void mergeSort(int start, int end, vector<ListNode *> &lists) {
    if (start < end) {
      int mid = (start + end) / 2;
      mergeSort(start, mid, lists);
      mergeSort(mid + 1, end, lists);
      merge(start, mid, end, lists);
    }
  }

  void merge(int start, int mid, int end, vector<ListNode *> &lists) {
    ListNode *temp1 = lists[start];
    ListNode *temp2 = lists[mid + 1];
    ListNode dummy = ListNode(0);
    ListNode *k = &dummy;

    while (temp1 && temp2) {
      if (temp1->val <= temp2->val) {
        k->next = new ListNode(temp1->val);
        temp1 = temp1->next;
      } else {
        k->next = new ListNode(temp2->val);
        temp2 = temp2->next;
      }
      k = k->next;
    }

    while (temp1) {

      k->next = new ListNode(temp1->val);
      k = k->next;
      temp1 = temp1->next;
    }

    while (temp2) {
      k->next = new ListNode(temp2->val);
      k = k->next;
      temp2 = temp2->next;
    }

    lists[start] = dummy.next;
  }
};

int main() { Solution s{}; }
