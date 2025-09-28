#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {

    int l = 0;
    int r = height.size() - 1;

    int leftMax = height[l];
    int rightMax = height[r];

    int result{};

    while (l < r) {
      if (leftMax < rightMax) {
        result += (leftMax - height[l]);
        l++;
        leftMax = max(leftMax, height[l]);
      } else {
        result += (rightMax - height[r]);
        r--;
        rightMax = max(rightMax, height[r]);
      }
    }

    return result;
  }
};

int main() {
  Solution O{};
  vector<int> input{0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  O.trap(input);
}
