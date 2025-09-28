#include <iostream>
#include <vector>

using namespace std;

struct node {
  int key;
  int value;
  node *next;
  node *pre;

  node(int k, int v) : key(k), value(v), next(nullptr), pre(nullptr) {}
  node(int k, int v, node *n) : key(k), value(v), next(n), pre(nullptr) {}
  node(int k, int v, node *n, node *p) : key(k), value(v), next(n), pre(p) {}
};

class LRUCache {
public:
  LRUCache(int capacity) {
    cap = capacity;
    head = nullptr;
    tail = nullptr;
  }

  int get(int key) {
    // delete the existed node
    // insert first node
  }

  void put(int key, int value) {

    if (curNum == 0) {
      node *temp = new node(key, value);
      head = tail = temp;
      um[key] = temp;
      curNum++;
      return;
    }

    if (um.find(key) != um.end()) {
      node *erased = um[key];

      if (erased->pre == nullptr) {
        head = erased->next;
      } else {
        erased->pre->next = erased->next;
      }

      if (erased->next = nullptr) {
        tail = erased->pre;
      } else {
        erased->next->pre = erased->pre;
      }

      delete erased;

      node *inserted = new node(key, value);
      if (head == nullptr) {
        head = tail = inserted;

      } else {
        inserted->next = head;
        head->pre = inserted;
        head = inserted;
      }
      um[key] = inserted;
    } else {
      if (cap == curNum) {
        // last pop
        node *temp = tail;

        delete temp;
        // first insert

      } else {
        // just first insert
        curNum++;
      }
    }
  }

  unordered_map<int, node *> um{};
  int cap{0};
  int curNum{0};
  node *head;
  node *tail;
};

int main() { Solution s{}; }
