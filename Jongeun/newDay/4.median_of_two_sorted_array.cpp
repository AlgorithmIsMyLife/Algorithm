#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    double l = 0, r = 0;

    if (m == 0 && n == 0) {
      return 0;
    } else if (m == 0) {
      int idx = (n + 1) / 2 - 1;
      if (n % 2 == 0) {
        // must calculate average btw 2 values
        return (nums2[idx] + nums2[idx + 1]) / (double)2;
      } else {
        return nums2[idx];
      }

    } else if (n == 0) {

      int idx = (m + 1) / 2 - 1;
      if (m % 2 == 0) {
        // must calculate average btw 2 values
        return (nums1[idx] + nums1[idx + 1]) / (double)2;
      } else {
        return nums1[idx];
      }

    } else {
      l = min(nums1[0], nums2[0]);
      r = max(nums1[m - 1], nums2[n - 1]);
    }

    double key;
    int midNum = (m + n + 1) / 2;

    int num1 = -1;
    int num2 = -1;
    int nums1Idx = -1;
    int nums2Idx = -1;

    while ((num1 + num2) != midNum) {

      key = (l + r) / (double)2;
      int pre1Idx = nums1Idx;
      int pre2Idx = nums2Idx;

      nums1Idx = lowBound(-1, m, key, nums1);
      nums2Idx = lowBound(-1, n, key, nums2);

      if (pre1Idx == nums1Idx && pre2Idx == nums2Idx) {
        if (nums1Idx == -1 && nums2Idx == -1)
          return nums1[0];
        else if (nums1Idx == -1)
          return nums2[nums2Idx];
        else
          return nums1[nums1Idx];
      }

      num1 = (nums1Idx == -1) ? 0 : nums1Idx + 1;
      num2 = (nums2Idx == -1) ? 0 : nums2Idx + 1;

      if (num1 + num2 > midNum) {
        r = key;
      } else if (num1 + num2 < midNum) {
        l = key;
      }
    }

    if ((m + n) % 2 == 0) {
      int left, right;
      if (nums1Idx == -1) {
        left = nums2[nums2Idx];
      } else if (nums2Idx == -1) {
        left = nums1[nums1Idx];
      } else {
        left = max(nums1[nums1Idx], nums2[nums2Idx]);
      }

      int right1 = (nums1Idx != m - 1) ? nums1[nums1Idx + 1] : 1000001;
      int right2 = (nums2Idx != n - 1) ? nums2[nums2Idx + 1] : 1000001;
      right = min(right1, right2);

      return (left + right) / (double)2;

    } else {

      if (nums1Idx == -1)
        return nums2[nums2Idx];
      else if (nums2Idx == -1)
        return nums1[nums1Idx];

      return max(nums1[nums1Idx], nums2[nums2Idx]);
    }
  }

  int lowBound(int l, int r, double key, vector<int> &v) {

    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (key > v[mid]) {
        l = mid;
      } else {
        r = mid;
      }
    }

    return l;
  }
};

int main() {
  Solution s{};
  vector<int> input1{0, 0, 0, 0, 0};
  vector<int> input2{-1, 0, 0, 0, 0, 0, 1};
  s.findMedianSortedArrays(input1, input2);
}
