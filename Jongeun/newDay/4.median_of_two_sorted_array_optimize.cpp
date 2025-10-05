#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    int m = nums1.size();
    int n = nums2.size();

    if (n > m) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int half = (n + m + 1) / 2;

    if (n == 0 && m != 0) {
      if (m % 2 == 0) {
        return (nums1[half - 1] + nums1[half]) / (double)2;

      } else {
        return nums1[half - 1];
      }
    }

    int l = 0;
    int h = m;

    while (l <= h) {

      int mid = (l + h) / 2;
      int mid2 = half - mid - 2;

      int leftNums1 = (mid < 0) ? INT_MIN : nums1[mid];
      int rightNums1 = ((mid + 1) >= m) ? INT_MAX : nums1[mid + 1];
      int leftNums2 = (mid2 < 0) ? INT_MIN : nums2[mid2];
      int rightNums2 = ((mid2 + 1) >= n) ? INT_MAX : nums2[mid2 + 1];

      if (leftNums1 <= rightNums2 && leftNums2 <= rightNums1) {
        if ((m + n) % 2 == 0) {
          int left = max(leftNums1, leftNums2);
          int right = min(rightNums1, rightNums2);
          return (left + right) / (double)2;
        } else {
          return max(leftNums1, leftNums2);
        }
      } else if (leftNums2 > rightNums1) {
        l = mid;
      } else if (leftNums1 > rightNums2) {
        h = mid;
      }
    }

    return -1;
  }
};

int main() {
  Solution s{};
  vector<int> nums1{};
  vector<int> nums2{2, 3};
  s.findMedianSortedArrays(nums1, nums2);
}
