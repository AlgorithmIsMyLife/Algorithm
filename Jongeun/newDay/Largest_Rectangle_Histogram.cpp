#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int maxSize{0};
    stack<pair<int, int>> stk;

    for (int i = 0; i < heights.size(); i++) {
      if (i == 0) {
        stk.push({heights[i], i});
        continue;
      }

      if (!stk.empty() && stk.top().first < heights[i]) {
        stk.push({heights[i], i});
      } else {
        int idx{i};

        while (!stk.empty() && heights[i] <= stk.top().first) {
          idx = stk.top().second;
          int tempHeight = stk.top().first;
          maxSize = max(maxSize, (i - idx) * tempHeight);
          stk.pop();
        }

        stk.push({heights[i], idx});
      }
    }

    int size = heights.size();

    while (!stk.empty()) {
      int height = stk.top().first;
      int idx = stk.top().second;
      maxSize = max(maxSize, height * (size - idx));
      stk.pop();
    }

    return maxSize;
  }
};

int main() {
  Solution s{};
  vector<int> input{7, 1, 7, 2, 2, 4};
  s.largestRectangleArea(input);
}
