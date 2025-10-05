// segtree version
#include <iostream>
#include <vector>

using namespace std;

class segtree {
public:
  segtree(const vector<int> &nums) : arr(nums), st(arr.size() * 4) {
    build(1, 0, arr.size() - 1);
  }

  void build(int node, int l, int r) {

    if (l == r) {
      st[node] = arr[l];
    } else {
      int mid = (l + r) / 2;
      build(node * 2, l, mid);
      build(node * 2 + 1, mid + 1, r);
      st[node] = max(st[node * 2], st[node * 2 + 1]);
    }
  };

  int query(int node, int start, int end, int l, int r) {
    if (end < l || r < start) {
      return INT_MIN;
    }

    if (l <= start && end <= r) {
      return st[node];
    }

    int lMax = query(node * 2, start, (start + end) / 2, l, r);
    int rMax = query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    return max(lMax, rMax);
  }

  vector<int> arr;
  vector<int> st;
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    segtree s(nums);
    vector<int> res;
    int l = 0;
    int r = k - 1;

    while (r < nums.size()) {
      int temp = s.query(1, 0, nums.size() - 1, l, r);
      res.push_back(temp);
      l++;
      r++;
    }

    return res;
  }
};

int main() { Solution s{}; }
