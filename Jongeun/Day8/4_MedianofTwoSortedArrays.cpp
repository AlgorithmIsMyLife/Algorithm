#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int total = nums1.size() + nums2.size();
        int half = total / 2;

        if (nums1.size() < nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // nums2 size is always smaller

        int l = 0;
        int r = nums2.size() - 1;

        double median = 0.0;
        while (true)
        {
            int mid = (l + r) / 2;
            int nums1L = half - mid - 2; // nums1 partition index

            int left1 = (nums1L >= 0) ? nums1[nums1L] : INT_MIN;
            int right1 = (nums1L + 1 < nums1.size()) ? nums1[nums1L + 1] : INT_MAX;
            int left2 = (mid >= 0) ? nums2[mid] : INT_MIN;
            int right2 = (mid + 1 < nums2.size()) ? nums2[mid + 1] : INT_MAX;

            if (left1 > right2)
            {
                l = mid + 1;
            }
            else if (left2 > right1)
            {
                r = mid - 1;
            }
            else
            {
                if (total % 2 == 0)
                {
                    double medianL = max(left1, left2);
                    double medianR = min(right1, right2);
                    median = (medianL + medianR) / 2;
                }
                else
                { // odd
                    median = min(right1, right2);
                }
                break;
            }
        }

        return median;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << obj.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
