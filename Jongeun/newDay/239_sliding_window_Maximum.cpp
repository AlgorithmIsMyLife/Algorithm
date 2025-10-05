#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {

    vector<int> res;
    int l = 0;
    int r = 0;
    deque<int> d; // store index
    d.push_back(0);
    r++;

    while (r < k) {
      while (!d.empty() && nums[r] >= nums[d.back()]) {
        d.pop_back();
      }

      d.push_back(r);
      r++;
    }
    res.push_back(nums[d.front()]);

    while (r < nums.size()) {
      if (l == d.front()) {
        d.pop_front();
      }
      l++;

      while (!d.empty() && nums[r] >= nums[d.back()]) {
        d.pop_back();
      }
      d.push_back(r);
      r++;

      res.push_back(nums[d.front()]);
    }
    return res;
  }
};

int main() {
  vector<int> input{1, 3, 1, 2, 0, 5};
  Solution s{};
  s.maxSlidingWindow(input, 3);
}
