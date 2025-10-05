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
    if (um[key] == nullptr) {
      return -1;
    }

    node *erased = um[key];
    int value = erased->value;

    if (erased->pre == nullptr) {
      head = erased->next;
    } else {
      erased->pre->next = erased->next;
    }

    if (erased->next == nullptr) {
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

    return value;

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

    if (um[key] != nullptr) {
      // update
      node *erased = um[key];

      if (erased->pre == nullptr) {
        head = erased->next;
      } else {
        erased->pre->next = erased->next;
      }

      if (erased->next == nullptr) {
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
        int k = temp->key;
        if (temp->pre == nullptr) {
          head = tail = nullptr;
        } else {
          tail = temp->pre;
          tail->next = nullptr;
        }

        delete temp;
        um[k] = nullptr;

        // first insert
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
        // just first insert
        curNum++;
        node *temp = new node(key, value);

        if (head == nullptr) {
          head = tail = temp;
        } else {
          temp->next = head;
          head->pre = temp;
          head = temp;
        }

        um[key] = temp;
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
